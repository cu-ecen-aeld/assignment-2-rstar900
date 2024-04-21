#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
    // Declarations
    int fd = -1;
    int wrstatus = -1;

    // Should be called with ./writer <file> <writestr>
    // Checking if atleast 2 arguments are there (3 as it includes executable name as well in this case)
    if (argc < 3)
    {
        // print the error on stderr and exit with status code of EXIT_FAILURE
        fprintf(stderr, "Usage: ./writer <file> <writestr>\n");
        return EXIT_FAILURE; 
    }

    // Initialize Syslog for logging (NULL as identity means that we use program name)
    // Using LOG_USER facility and 0 as option
    openlog(NULL, 0, LOG_USER);

    // In this case we expect there to be a valid directory given
    // So no need to make a new one here
    // Simply open a new file for writing and log any errors if they exist
    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
    {
        syslog(LOG_ERR, "%s", strerror(errno));
        return EXIT_FAILURE;
    }

    
    // Use the syslog capability to write a message “Writing <string> to <file>” 
    // This should be written with LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    // Write to file and log any errors if they exist
    if ((wrstatus = write(fd, argv[2], strlen(argv[2]))) == -1)
    {
        syslog(LOG_ERR, "%s", strerror(errno));
        return EXIT_FAILURE;
    }
    
    // If exerything went well, then close syslog and exit with success exit code (=0)
    closelog();
    return EXIT_SUCCESS;
}