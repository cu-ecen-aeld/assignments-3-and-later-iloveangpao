#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in Test_assignment_validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    char *username_from_conf = malloc_username_from_conf_file();
    if (username_from_conf == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
    }

    // Directly use the constant string for the second username
    const char *username_const = my_username();

    // Allocate memory for the destination arrays
    char dest1[100]; // Ensure the destination array is large enough
    char dest2[100];

    // Copy the strings
    strcpy(dest1, username_from_conf);
    strcpy(dest2, username_const);

    // Print the copied strings
    printf("Username from conf file: %s\n", dest1);
    printf("My username: %s\n", dest2);

    // Free dynamically allocated memory
    free(username_from_conf);

    TEST_ASSERT_EQUAL_STRING_MESSAGE(dest1, dest2,"DIFFERENT USERNAME");
}
