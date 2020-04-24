#include <iostream>

using namespace std;
enum SEX { u, m, f };

class Human {
  int age;
  SEX sex;
  bool work;
  string fio;

public:
  Human(int age, SEX sex, bool work, string fio) : age(age) {
    this->fio = fio;
    this->work = work;
    this->sex = sex;
  }
  const string &getFio() const { return fio; }
  void setFio(const string &fio) { this->fio = fio; }

  bool getWork() const { return work; }
  void setWork(bool work) { this->work = work; }

  int getAge() const { return age; }
  void setAge(int age) { this->age = age; }
  int getSex() const { return sex; }
  void setSex(SEX sex) { this->sex = sex; }
};

class Student : public Human {
  string numberofzachetka;

public:
  Student(int age, SEX sex, bool work, string fio,
          const string &numberofzachetka)
      : Human(age, sex, work, fio) {
    this->numberofzachetka = numberofzachetka;
  }
  const string &getNumberofzachetka() const { return numberofzachetka; }

  void setNumberofzachetka(string numberofzachetka) {
    this->numberofzachetka = numberofzachetka;
  }
};

class BudgetStudent : public Student {
  bool stependia;

public:
  BudgetStudent(int age, SEX sex, bool work, string fio,
                const string &numberofzachetka, bool stependia)
      : Student(age, sex, work, fio, numberofzachetka) {
    this->stependia = stependia;
  }
  bool getStependia() const { return stependia; }
  void setStependia(bool stependia) { this->stependia = stependia; }
};

class ContractStudent : public Student {
  int costofeducation;

public:
  ContractStudent(int age, SEX sex, bool work, const string &fio,
                  const string &numberofzachetka, int costofeducation)
      : Student(age, sex, work, fio, numberofzachetka) {
    this->costofeducation = costofeducation;
  }
  int getcostofeducation() const { return costofeducation; }
  void setcostofeducation(int costofeducation) {
    ContractStudent::costofeducation = costofeducation;
  }
};

class Professor : public ContractStudent, public BudgetStudent {
  string sieneces;

public:
  Professor(int age, SEX sex, bool work, const string &fio,
            const string &numberofzachetka, int costofeducation, bool stependia,
            string sieneces)
      : ContractStudent(age, sex, work, fio, numberofzachetka, costofeducation),
        BudgetStudent(age, sex, work, fio, numberofzachetka, stependia) {
    this->sieneces = sieneces;
  }
  const string &getSieneces() const { return sieneces; }
  void setSieneces(const string &sieneces) { Professor::sieneces = sieneces; }
};

int main() {
  Human vova(24, SEX::m, true, "vova");
  cout << vova.getFio() << endl;

  Student tom(18, SEX::m, false, "tom", "d56465kf");
  cout << tom.getNumberofzachetka() << endl;

  BudgetStudent tomara(19, SEX::f, true, "tomara", "d896456kf", true);
  cout << tomara.getStependia() << endl;

  ContractStudent ira(19, SEX::f, true, "ira", "d896456kf", 182000);
  cout << ira.getcostofeducation() << endl;

  Professor inna(49, SEX::f, true, "inna", "d896456kf", true, 0, "ljoi");
  cout << inna.getSieneces() << endl;

  cout << "Hello, World!" << endl;
  return 0;
}