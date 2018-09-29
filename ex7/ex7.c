#include <stdio.h>

int main(int argc, char* argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'S';
    char first_name[] = "Michael";
    char last_name[] = "Fedell";

    // last_name is a string of size 5 meaning that 'F' is indexed
    // at last_name[0], 'd' at last_name[2] and so on to 'l' at last_name[5].
    // In C, strings are terminated with a nul_byte so there is actually
    // a '\0' indexed at last_name[7]. If we overwrite that '\0', C will not
    // stop at end of string and will keep reading into memory.
    // This is a serious problem yet raises no warnings or errors!

    // last_name[6] = '@';

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super_powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My full name is %c. %s %s.\n",
            initial, first_name, last_name);

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the univers.\n",
            part_of_universe);

    // This makes no sense, just a demo of something weird.
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;
}
