#!/bin/bash

### Edit the path to your hpp files here
vector_path='..'
map_path='..'
stack_path='..'
#########################################

NORMAL=$(tput sgr0)
BLACK=$(tput setaf 0)
RED=$(tput setaf 160)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
POWDER_BLUE=$(tput setaf 153)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
WHITE=$(tput setaf 7)
BRIGHT=$(tput bold)
BLINK=$(tput blink)
REVERSE=$(tput smso)
UNDERLINE=$(tput smul)

function title {
    echo ""
    echo -e "${GREEN} ██████  ██████  ███    ██ ████████  █████  ██ ███    ██ ███████ ██████  ███████"
    echo -e "${YELLOW}██      ██    ██ ████   ██    ██    ██   ██ ██ ████   ██ ██      ██   ██ ██     "
    echo -e "${RED}██      ██    ██ ██ ██  ██    ██    ███████ ██ ██ ██  ██ █████   ██████  ███████"
    echo -e "${MAGENTA}██      ██    ██ ██  ██ ██    ██    ██   ██ ██ ██  ██ ██ ██      ██   ██      ██"
    echo -e "${CYAN} ██████  ██████  ██   ████    ██    ██   ██ ██ ██   ████ ███████ ██   ██ ███████${BRIGHT} unit tests ${NORMAL}"
    echo ""
}

function spinner {

    char=(\| / – \\)
    delay=0.1
    pid=$!
    i=0

    while kill -0 $pid 2>/dev/null; do
        for ((i=0; i<=3; i++)); do
            echo -n ${char[$i]}
            sleep $delay
            echo -ne '\b'
        done
    i=0
    done
    echo " "
}

function testing_vector {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                  VECTOR                                    */\n"
    printf "/* ************************************************************************** */\n${NORMAL}"
    printf "\n\U1F4D8 Running tests with the STL... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL vector_tests.cpp && ./a.out > vector_stl_output.log & spinner) 
    printf "\n\U1F530 Running tests with your vector... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${vector_path} vector_tests.cpp && ./a.out > vector_your_output.log & spinner) 
    printf "\n\U1F440 Comparing both outputs...\n"
    if diff vector_stl_output.log vector_your_output.log
    then
        printf "${BRIGHT}\n>>> VECTOR TESTS CLEAR \u2705\n"
        rm -rf vector*.log
    else
        printf "${BRIGHT}\n>>> VECTOR TESTS KO \u274C\n"
        printf "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

function testing_stack {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                   STACK                                    */\n"
    printf "/* ************************************************************************** */\n${NORMAL}"
    printf "\n\U1F4D8 Running tests with the STL... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL stack_tests.cpp && ./a.out > stack_stl_output.log & spinner) 
    printf "\n\U1F530 Running tests with your stack... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${stack_path} stack_tests.cpp && ./a.out > stack_your_output.log & spinner) 
    printf "\n\U1F440 Comparing both outputs...\n"
    if diff stack_stl_output.log stack_your_output.log
    then
        printf "${BRIGHT}\n>>> STACK TESTS CLEAR \u2705\n"
        rm -rf stack*.log
    else
        printf "${BRIGHT}\n>>> STACK TESTS KO \u274C\n"
        printf "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

function testing_map {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                    MAP                                     */\n"
    printf "/* ************************************************************************** */\n${NORMAL}"
    printf "\n\U1F4D8 Running tests with the STL... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL map_tests.cpp && ./a.out > map_stl_output.log & spinner)
    printf "\n\U1F530 Running tests with your map... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${map_path} map_tests.cpp && ./a.out > map_your_output.log & spinner)
    printf "\n\U1F440 Comparing both outputs...\n"
    if diff map_stl_output.log map_your_output.log
    then
        printf "${BRIGHT}\n>>> MAP TESTS CLEAR \u2705\n"
        rm -rf map*.log
    else
        printf "${BRIGHT}\n>>> MAP TESTS KO \u274C\n"
        printf "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

title
if [  "$1" == "vector" ]; then
    testing_vector
elif [  "$1" == "stack" ]; then
    testing_stack
elif [  "$1" == "map" ]; then
    testing_map
else
    testing_vector
    testing_stack
    testing_map
fi
rm -f a.out