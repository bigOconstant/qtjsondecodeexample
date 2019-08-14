#include <QApplication>
#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QString val;
        QFile file;
        file.setFileName("../jsondecode/testdata.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

    QWidget window;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(val.toUtf8());
    QJsonArray jsonArray = jsonResponse.array();


    window.resize(250, 150);

     window.setWindowTitle(jsonArray[0].toString());
    window.show();

    return app.exec();
}
