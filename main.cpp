#include <QFile>
#include <QtDebug>
int main(int argc, char* argv[])
{
	QFile someFile("sample.txt");
	if (!someFile.exists())
	{
		qDebug() << "Error -- file does not exist";
	}
	else if (!someFile.open(QIODevice::ReadOnly |
			 QIODevice::Text))
	{
		qDebug() << "Error -- unable to open file for input";
	}
	else
	{
		qDebug() << "File opened for input successfully";
		QTextStream someStream(&someFile);
		QString someValue;
		while (!someStream.atEnd())
		{
			someStream >> someValue;
			qDebug() << someValue;
		}
		someFile.close();
	}
	
	return 0;
}
