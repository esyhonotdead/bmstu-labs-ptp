#!/bin/bash

VERBOSE=false
total_positive=0
total_negative=0
passed_positive=0
passed_negative=0

[[ "$1" == "-v" ]] && VERBOSE=true

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

run_test_suite() {
    local test_type=$1
    local pattern=$2

    local found=false
    for file in "$SCRIPT_DIR"/../data/"$pattern"*_in.txt; do
        [ -f "$file" ] && found=true && break
    done

    if ! $found; then
        $VERBOSE && echo "-----------------------------" && \
        echo "${test_type^} tests were not found" && echo
        return
    fi

    if $found; then
        $VERBOSE && echo "----------------------" && \
        echo "RUNNING ${test_type^^} TESTS" && echo

        for in_file in "$SCRIPT_DIR"/../data/"$pattern"_*_in.txt; do
            out_file="${in_file/_in/_out}"
            [ ! -f "$out_file" ] && [ "$test_type" == "pos" ] && continue

            if [ "$test_type" == "pos" ]; then
                ((total_positive++))
            else
                ((total_negative++))
            fi

            if "$SCRIPT_DIR/${test_type}_case.sh" "$in_file" "$out_file"; then
                if [ "$test_type" == "pos" ]; then
                    ((passed_positive++))
                else
                    ((passed_negative++))
                fi
                $VERBOSE && echo -e "$(basename "$in_file"): \e[32mPASSED\e[0m"
            else
                $VERBOSE && handle_failure "$in_file" "$out_file"
            fi
        done
    fi
}

handle_failure() {
    echo -e "$(basename "$1"): \e[31mFAILED\e[0m"
    echo
    echo -e "Input data:\n$(sed 's/^/\t/' "$1")"
    echo -e "Expected output:\n$(sed 's/^/\t/' "$2")"
    echo -e "Actual output:\n$(sed 's/^/\t/' current.txt)"
    echo
}

run_test_suite "pos" "pos"
run_test_suite "neg" "neg"

echo "================================"
echo "TESTING IS OVER"
echo "STATS DOWN BELOW"
echo "================================"
echo

print_stats() {
    local total=$1
    local passed=$2
    local type=$3
    
    echo -e "Total $type tests: $total"
    if [ "$passed" -eq "$total" ]; then
        echo -e "$type tests passed: \e[32m$passed/$total\e[0m"
    else
        echo -e "$type tests passed: \e[31m$passed\e[0m/\e[32m$total\e[0m"
    fi
    echo "--------------------------------"
}

print_stats "$total_positive" "$passed_positive" "positive"
print_stats "$total_negative" "$passed_negative" "negative"

echo "======================================"
if [ $((passed_positive + passed_negative)) -eq $((total_positive + total_negative)) ]; then
    echo -e "\e[32mALL TESTS HAVE BEEN PASSED\e[0m"
else
    echo -e "\e[31mNOT ALL TESTS HAVE BEEN PASSED\e[0m"
fi
echo "======================================"