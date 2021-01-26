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
    const char* const short_options = "hm:t:b:";

    // Array with possible long options.
    const struct option long_options[] =
    {
        { "help", no_argument, NULL, 'h' },
        { "message", required_argument, NULL, 'm' },
        { "dtitle", required_argument, NULL, 't' },
        { "btntext", required_argument, NULL, 'b' },
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
                      w.SetButtonText(optarg);
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
    fprintf(stdout, "*** show-message - simple program which show dialog with custom text message. ***\n\n");
    fprintf(stdout, "Usage: %s [options] \n", program_name);
    fprintf(stdout, "%4s, %-30s %s\n", "-h", "--help", "Display this help and exit.");
    fprintf(stdout, "%4s, %-30s %s\n", "-m", "--message \"Text message\"", "Text string which will show in dialog (default \"Message Text\"). You can use HTML markup language for better view.");
    fprintf(stdout, "%4s, %-30s %s\n", "-t", "--dtitle \"Dialog title\"", "This text will show in dialog header (default \"Message\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-b", "--btntext \"Ok\"", "Button will labeled with this text (default \"Ok\").");
}
