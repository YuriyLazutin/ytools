#include "dialog.h"
#include <QTextStream>
#include <QRegExpValidator>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setObjectName(QString::fromUtf8("Dialog"));
    setMinimumSize(QSize(300, 120));
    uWidth = minimumWidth();
    uHeight = minimumHeight();
    resize(uWidth, uHeight);
    //setMaximumSize(QSize(10000, 120)); // It work
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
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
    label->setAlignment(Qt::AlignLeft);
    verticalLayout->addWidget(label);

    // Add Line Edit
    leParamValue = new QLineEdit;
    leParamValue->setFocus();
    verticalLayout->addWidget(leParamValue);
    //leParamValue->setMinimumHeight(32);

    // Add spacer
    verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalLayout->addItem(verticalSpacer);

    // Create horizontal layout (Accept button group)
    hlAcceptBtn = new QHBoxLayout();
    hlAcceptBtn->setObjectName(QString::fromUtf8("hlAcceptBtn"));
      // Add spacer
      horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
      hlAcceptBtn->addItem(horizontalSpacerLeft);
      // Add "Accept" button
      btnAccept = new QPushButton(this);
      btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
      btnAccept->setMinimumSize(QSize(100, 30));
      btnAccept->setAutoFillBackground(false);
      btnAccept->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      hlAcceptBtn->addWidget(btnAccept);
      // Add spacer
      //horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
      //hlAcceptBtn->addItem(horizontalSpacerRight);

    verticalLayout->addLayout(hlAcceptBtn);

    SetWindowTitle("Query parameter");
    SetMessageText("Please enter a parameter value");
    SetAcceptButtonText("Accept");
    SetDataType("string");
    SetDataMask("");

    connect(btnAccept, SIGNAL(clicked()), SLOT(BtnAcceptClicked()));
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

void Dialog::SetAcceptButtonText(const char* txt)
{
    btnAccept->setText(QApplication::translate("Dialog", txt, nullptr));
}

void Dialog::SetDataType(const char* dtype)
{
    sDataType = QString(dtype).toLower();
}

void Dialog::SetDataMask(const char* dmask)
{
    sDataMask = dmask;
}

void Dialog::SwitchOnValidator()
{
    QRegExpValidator val;
    QRegExp re;

    if (sDataType == "integer")
    {
        if (!sDataMask.isEmpty())
            re.setPattern("^[-+]?\\d{1,*}$");
        else
            re.setPattern(sDataMask);
    }
    else if (sDataType == "float")
        if (!sDataMask.isEmpty())
            re.setPattern("^([0-9]*|\\d*\\.\\d{1}?\\d*)$");
        else
            re.setPattern(sDataMask);
    else if (sDataType == "double")
    {
        if (!sDataMask.isEmpty())
            re.setPattern("^[+-]?([0-9]*\\.?[0-9]+|[0-9]+\\.?[0-9]*)([eE][+-]?[0-9]+)?$");
        else
            re.setPattern(sDataMask);
    }
    else if (sDataType == "date")
    {
        if (!sDataMask.isEmpty())
            re.setPattern("^\\d{4}[\\-\\/\\s]?((((0[13578])|(1[02]))[\\-\\/\\s]?(([0-2][0-9])|(3[01])))|(((0[469])|(11))[\\-\\/\\s]?(([0-2][0-9])|(30)))|(02[\\-\\/\\s]?[0-2][0-9]))$");
        else
            re.setPattern(sDataMask);
    }
    else // sDataType == "string" and others
    {
        if (!sDataMask.isEmpty())
            re.setPattern("");
        else
            re.setPattern(sDataMask);
    }
    val.setRegExp(re);
    leParamValue->setValidator(&val);
}

void Dialog::SetSizeX(const int sx)
{
    sx < minimumWidth() ? uWidth = minimumWidth() : uWidth=sx;
    resize(uWidth, uHeight);
}
void Dialog::SetSizeY(const int sy)
{
    sy < minimumHeight() ? uHeight = minimumHeight() : uHeight=sy;
    resize(uWidth, uHeight);
}

void Dialog::BtnAcceptClicked()
{
    if( leParamValue->hasAcceptableInput() )
    {
        QTextStream out(stdout);
        out << leParamValue->text() << endl;
        qApp->quit();

    }
    else
    {
        //leParamValue->setColor(Qt:red);
    }

}
