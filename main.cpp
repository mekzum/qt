


#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>
#include <QDebug>

QStringList array;
int main(int argc, char *argv[])
{

     QCoreApplication app(argc, argv);


       qDebug()<<argc;
      for(int i=0; i<argc; i++) qDebug() << argv[i];

    QCoreApplication::setApplicationName("Demo");
    QCoreApplication::setOrganizationName("Bean");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription("Line Parser");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("url", "The URL to open.");




    QCommandLineOption targetDirectoryOption(QStringList() << "t" << "target-directory" <<"par1" <<"par2",
                QCoreApplication::translate("main", "Copy all source files into <directory>."),
                QCoreApplication::translate("main", "directory"),
              // QCoreApplication::translate("main", "directory"),
                QCoreApplication::translate("main", "directory"));
        parser.addOption(targetDirectoryOption);

        QCommandLineOption getFirstInt(QStringList() << "first" , QCoreApplication::translate("main", "Option is: fr") \
                                           ,"first value for sum");
        parser.addOption(getFirstInt);

        QCommandLineOption getSecondInt(QStringList() << "second" , QCoreApplication::translate("main", "Option is: fr") \
                                           ,"second value for sum");
        parser.addOption(getSecondInt);

         parser.process(app);
   // Player player;

         array=parser.values(getFirstInt);
         qDebug()<<array;
         array=parser.values(getSecondInt);
         qDebug()<<array;


/*    if (!parser.positionalArguments().isEmpty() ) {

array=parser.values(getFirstInt);
qDebug()<<array;
array=parser.values(getSecondInt);
qDebug()<<array;
     //   QList<QUrl> urls;
     //   for (auto &a: parser.positionalArguments())
       //     urls.append(QUrl::fromUserInput(a, QDir::currentPath(), QUrl::AssumeLocalFile));
       // player.addToPlaylist(urls);
    }
else parser.showHelp(1);*/
 //   player.show();
    return 0;
}
