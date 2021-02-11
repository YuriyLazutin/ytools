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
    const char* const short_options = "hq:t:a:b:mx:y:";

    // Array with possible long options.
    const struct option long_options[] =
    {
        { "help", no_argument, NULL, 'h' },
        { "question", required_argument, NULL, 'q' },
        { "dtitle", required_argument, NULL, 't' },
        { "yesbtn", required_argument, NULL, 'a' },
        { "nobtn", required_argument, NULL, 'b' },
        { "morpheus", no_argument, NULL, 'm' },
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
            // -q or --question
            case 'q':
                      w.SetQuestionText(optarg);
                      break;
            // -t or --dtitle
            case 't':
                      w.SetWindowTitle(optarg);
                      break;
            // -a or --yesbtn
            case 'a':
                      w.SetYesButtonText(optarg);
                      break;
            // -b or --nobtn
            case 'b':
                      w.SetNoButtonText(optarg);
                      break;
            // -m or --morpheus
            case 'm':
                      w.SetMorpheus();
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
    fprintf(stdout, "*** query-yesno - this tool will show a dialog in which you can specify a simple question, assumes what the response will be \"yes\" or \"no\". ***\n\n");
    fprintf(stdout, "Usage: %s [options] \n", program_name);
    fprintf(stdout, "%4s, %-30s %s\n", "-h", "--help", "Display this help and exit.");
    fprintf(stdout, "%4s, %-30s %s\n", "-q", "--question \"Your question\"", "Text string which will show in dialog (default \"Please select Yes or No\"). Please use it for clarifying you request. You can use HTML markup language for better view.");
    fprintf(stdout, "%4s, %-30s %s\n", "-t", "--dtitle \"New dialog title\"", "This text will show in dialog header (default \"Make your choise\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-a", "--yesbtn \"New btn label\"", "\"Yes\" button will labeled with this text (default \"Yes\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-b", "--nobtn \"New btn label\"", "\"No\" button will labeled with this text (default \"No\").");
    fprintf(stdout, "%4s, %-30s %s\n", "-m", "--morpheus", "If you specify this option a picture with Morpheus from Matrix will shown.");
    fprintf(stdout, "%4s, %-30s %s\n", "-x", "--sizex window_width", "This parameter allow you to customize window width (default 270 pixels, minimum 270).");
    fprintf(stdout, "%4s, %-30s %s\n", "-y", "--sizey window_height", "This parameter allow you to customize window height (default 120 pixels, minimum 120).");
}
