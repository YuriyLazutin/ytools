#include <QApplication>
#include "dialog.h"
#include <getopt.h> // getopt_long, no_argument, required_argument, optarg, optind

// Print help message and exit.
void print_help();
char* program_name;

int main(int argc, char** argv)
{
    program_name = argv[0];
    QApplication a(argc, argv);
    Dialog w;

    int next_option;

    // String with possible short options
    const char* const short_options = "hm:t:b:x:y:";

    // Array with possible long options.
    const struct option long_options[] =
    {
        { "help", no_argument, NULL, 'h' },
        { "message", required_argument, NULL, 'm' },
        { "dtitle", required_argument, NULL, 't' },
        { "btntext", required_argument, NULL, 'b' },
        { "sizex", required_argument, NULL, 'x' },
        { "sizey", required_argument, NULL, 'y' },
        { NULL, 0, NULL, 0 }
    };

    do
    {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
            // -h or --help
            case 'h':
                      print_help();
                      return (EXIT_SUCCESS);
            // -m or --message
            case 'm':
                      w.SetMessageText(optarg);
                      break;
            // -t or --dtitle
            case 't':
                      w.SetWindowTitle(optarg);
                      break;
            // -b or --btntext
            case 'b':
                      w.SetAcceptButtonText(optarg);
                      break;
            // -x or --sizex
            case 'x':
                      unsigned int x;
                      x=atoi(optarg);
                      w.SetSizeX(x);
                      break;
            // -y or --sizey
            case 'y':
                      unsigned int y;
                      y=atoi(optarg);
                      w.SetSizeY(y);
                      break;
            // Incorrect option
            case '?':
                      print_help();
                      return (EXIT_FAILURE);
            // No more option
            case -1:
                     break;
            // Something wrong
            default:
                     abort();
        }
    }
    while (next_option != -1);

    w.show();
    return a.exec();
}

// Print help message and exit.
void print_help()
{
    fprintf(stdout, "*** query-password - a simple program which allow you to request a passwords. ***\n");
    fprintf(stdout, "You can specify a message text to clarify you request for user.\n");
    fprintf(stdout, "The inputed value will returned back to requesting program.\n\n");
    fprintf(stdout, "Usage: %s [options] \n", program_name);
    fprintf(stdout, "%4s, %-30s %s\n", "-h", "--help", "Display this help and exit.");
    fprintf(stdout, "%4s, %-30s %s\n", "-m", "--message \"Clarifying text\"", "Text string which will show in dialog (default \"Please enter your password\"). Please use it for clarifying you request. You can use HTML markup language for better view.");
    fprintf(stdout, "%4s, %-30s %s\n", "-t", "--dtitle \"New dialog title\"", "This text will show in dialog header (default \"Password required\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-b", "--btntext \"New btn label\"", "Accept button will labeled with this text (default \"Accept\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-x", "--sizex window_width", "This parameter allow you to customize window width (default 300 pixels, minimum 300).");
    fprintf(stdout, "%4s, %-30s %s\n", "-y", "--sizey window_height", "This parameter allow you to customize window height (default 120 pixels, minimum 120).");
}
