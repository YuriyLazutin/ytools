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
    const char* const short_options = "hm:d:t:b:x:y:";

    // Array with possible long options.
    const struct option long_options[] =
    {
        { "help", no_argument, NULL, 'h' },
        { "message", required_argument, NULL, 'm' },
        { "directory", required_argument, NULL, 'd' },
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
            // -d or --directory
            case 'd':
                      w.SetBaseDirectory(optarg);
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
    fprintf(stdout, "*** query-directory-name - a simple program which allow you to use query dialog for select a directory name. ***\n\n");
    fprintf(stdout, "Usage: %s [options] \n", program_name);
    fprintf(stdout, "%4s, %-30s %s\n", "-h", "--help", "Display this help and exit.");
    fprintf(stdout, "%4s, %-30s %s\n", "-m", "--message \"Clarifying text\"", "Text string which will show in dialog (default \"Please select a directory\"). Please use it for clarifying you request. You can use HTML markup language for better view.");
    fprintf(stdout, "%4s, %-30s %s\n", "-d", "--directory \"/base/directory\"", "In this directory initially will open query directory dialog.  This parameter can be used to set up a default value.");
    fprintf(stdout, "%4s, %-30s %s\n", "-t", "--dtitle \"New dialog title\"", "This text will show in dialog header (default \"Query directory\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-b", "--btntext \"New btn label\"", "Accept button will labeled with this text (default \"Accept\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-x", "--sizex window_width", "This parameter allow you to customize window width (default 500 pixels, minimum 300).");
    fprintf(stdout, "%4s, %-30s %s\n", "-y", "--sizey window_height", "This parameter allow you to customize window height (default 120 pixels, minimum 120).");
}
