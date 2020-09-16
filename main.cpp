#include "student.h"
#include <QFile>
#include <QtDebug>

QDataStream& operator<<(QDataStream& ds, Student& s)
{
	ds << s.getName() << s.getAge() << s.getGrade();
	return ds;
}

QDataStream& operator>>(QDataStream& ds, Student& s)
{
	QString name;
	quint16 age;
	QChar grade;
	
	ds >> name >> age >> grade;
	s.setName(name);
	s.setAge(age);
	s.setGrade(grade);
	
	return ds;
}

int main(int argc, char* argv[])
{
	QFile outFile("sampleWrite.txt");
	if (!outFile.open(QIODevice::WriteOnly))
	{
		qDebug() << "Error -- unable to open file for output";
	}
	else
	{
		qDebug() << "File opened for input successfully";
		Student student1("Homer Simpson", 50, 'F');
		Student student2("Bart Simpson", 10, 'D');
		Student student3("Lisa Simpson", 8, 'A');
		
		QDataStream outStream(&outFile);
		outStream.setVersion( QDataStream::Qt_4_1);
		outStream << student1 << student2 << student3;
			
		outFile.close();
	}
	
	QFile inFile("sampleWrite.txt");
	if (!inFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Error -- unable to open file for input";
	}
	else
	{
		QDataStream inStream(&inFile);
		inStream.setVersion( QDataStream::Qt_4_1);
		
		Student s;
		
		while (!inFile.atEnd() )
		{
			inStream >> s;
			
			qDebug() << s.getName() << " " << s.getAge() << " " << s.getGrade();
		}
		
		inFile.close();
	}
	
	return 0;
}


