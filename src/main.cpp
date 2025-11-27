#include <QApplication>
#include <QStyleFactory>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Set application info
    app.setApplicationName("Beautiful UI");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("BeautifulApps");
    
    // Apply Fusion style as base for customization
    app.setStyle(QStyleFactory::create("Fusion"));
    
    // Create and show the main window
    MainWindow mainWindow;
    mainWindow.show();
    
    return app.exec();
}
