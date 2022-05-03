#!/bin/bash

NORMAL=$(tput sgr0)
BLACK=$(tput setaf 0)
RED=$(tput setaf 160)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
POWDER_BLUE=$(tput setaf 153)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 14)
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
    echo -e "${CYAN} ██████  ██████  ██   ████    ██    ██   ██ ██ ██   ████ ███████ ██   ██ ███████${WHITE}  express ${NORMAL}"
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
    printf "/* ************************************************************************** */\n\n${NORMAL}"
    printf "\U1F4D8 Running tests with the STL... "
    g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL vector_tests.cpp && ./a.out > vector_stl_output.log & spinner
    printf "\U1F530 Running tests with your vector... "
    g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra vector_tests.cpp && ./a.out > vector_your_output.log & spinner
    printf "\U1F440 Comparing both outputs...${BRIGHT}"
    if diff vector_stl_output.log vector_your_output.log & spinner
    then
        printf "\n>>> VECTOR TESTS CLEAR \u2705\n"
        rm -rf *.log
    else
        echo "\n>>> VECTOR TESTS KO \u274C\n"
        echo "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

function testing_map {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                    MAP                                     */\n"
    printf "/* ************************************************************************** */\n\n${NORMAL}"
    printf "\U1F4D8 Running tests with the STL... "
    g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL map_tests.cpp && ./a.out > map_stl_output.log & spinner
    printf "\U1F530 Running tests with your map... "
    g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra map_tests.cpp && ./a.out > map_your_output.log & spinner
    printf "\U1F440 Comparing both outputs...${BRIGHT}"
    if diff map_stl_output.log map_your_output.log & spinner
    then
        printf "\n>>> MAP TESTS CLEAR \u2705\n"
        rm -rf *.log
    else
        echo "\n>>> MAP TESTS KO \u274C\n"
        echo "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}


title
testing_vector
testing_map