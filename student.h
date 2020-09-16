#include <QFile>
#include <QtDebug>
#include <QString>
#include <QChar>
#include <QDataStream>
#include <QList>

class Student
{
	private:
		QString name;
		quint16 age;
		QChar grade;
		
	public:
		Student() { }
		Student(QString n, quint16 a, QChar g) {name = n; age = a; grade = g;}
		
		QString getName() {return name; }
		quint16 getAge() { return age; }
		QChar getGrade() { return grade; }
		
		void setName(QString n) {name = n;}
		void setAge(quint16 a) {age = a;}
		void setGrade(QChar g) {grade = g;}
};
