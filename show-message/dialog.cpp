#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{

    setObjectName(QString::fromUtf8("Dialog"));
    setMinimumSize(QSize(300, 120));
    uWidth = minimumWidth();
    uHeight = minimumHeight();
    resize(uWidth, uHeight);
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    szPolicy.setHorizontalStretch(0);
    szPolicy.setVerticalStretch(0);
    szPolicy.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(szPolicy);
    setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.5, fx:0.5, fy:0.5, stop:0 rgba(190, 200, 210, 255), stop:1 rgba(160, 200, 190, 223));"));

    // Add vertical layout
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    // Add label
    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
    label->setAlignment(Qt::AlignCenter);
    verticalLayout->addWidget(label);

    // Create horizontal layout
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacerLeft);
    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setMinimumSize(QSize(100, 30));
    pushButton->setAutoFillBackground(false);
    pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
    horizontalLayout->addWidget(pushButton);
    horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacerRight);

    verticalLayout->addLayout(horizontalLayout);

    SetWindowTitle("Message");
    SetMessageText("Message Text");
    SetButtonText("Ok");

    connect(pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connect(pushButton, SIGNAL(released()), qApp, SLOT(quit()));
}

Dialog::~Dialog()
{
}

void Dialog::SetMessageText(const char* msg)
{
    label->setText(QApplication::translate("Dialog", msg, nullptr));
}

void Dialog::SetWindowTitle(const char* title)
{
    setWindowTitle(QApplication::translate("Dialog", title, nullptr));
}

void Dialog::SetButtonText(const char* txt)
{
    pushButton->setText(QApplication::translate("Dialog", txt, nullptr));
}

void Dialog::SetSizeX(const unsigned int sx)
{
    sx < minimumWidth() ? uWidth = minimumWidth() : uWidth=sx;
    resize(uWidth, uHeight);
}
void Dialog::SetSizeY(const unsigned int sy)
{
    sy < minimumHeight() ? uHeight = minimumHeight() : uHeight=sy;
    resize(uWidth, uHeight);
}
