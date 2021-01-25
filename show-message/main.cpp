#include "dialog.h"

#include <QApplication>
#include <QString>

//#include <string.h>  // strlen
#include <getopt.h> // getopt_long, no_argument, required_argument, optarg, optind

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    Dialog w;

    int next_option;

    // String with possible short options
    const char* const short_options = "hm:t:";

    // Array with possible long options.
    const struct option long_options[] =
    {
        { "help", no_argument, NULL, 'h' },
        { "message", required_argument, NULL, 'm' },
        { "title", required_argument, NULL, 't' },
        { NULL, 0, NULL, 0 }
    };

    do
    {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
            // -h or --help
            case 'h':
                      //print_help();
                      //return (rc);
                      return a.exec();
            // -m or --message
            case 'm':
                      w.SetMessageText(optarg);
                      break;
            // -t or --title
            case 't':
                      w.SetWindowTitle(optarg);
                      break;
            // Incorrect option
            case '?':
                      // print_help();
                      return a.exec(); // ToDo: There should be returned error code!
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
