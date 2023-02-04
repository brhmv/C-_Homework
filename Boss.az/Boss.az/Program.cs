﻿using Boss.az;
using System.Text.Json;


List<Worker> Workers = new();

List<Employer> Employers = new();

List<Vacancy> AllVacancies = new();

#region Test

Employer e1 = new("ali", "aliyev", 42, "055", "baku");
Employer e2 = new("akif", "Alziade", 23, "050", "baku");
Employer e3 = new("aqil", "Agazade", 13, "070", "baku");

Vacancy v11 = new("it1", "a", 2000, 6, 45, Worktype.Remoute);
v11.FromWhichEmployer = e1;

Vacancy v12 = new("it1", "a", 100, 2, 50, Worktype.Freelance);
v12.FromWhichEmployer = e1;

Vacancy v21 = new("it2", "a", 30000, 1, 55, Worktype.Fulltime);
v21.FromWhichEmployer = e2;

Vacancy v22 = new("it2", "a", 1500, 3, 55, Worktype.Parttime);
v22.FromWhichEmployer = e2;

Vacancy v31 = new("it3", "a", 3000, 4, 65, Worktype.Freelance);
v31.FromWhichEmployer = e3;

Vacancy v32 = new("it3", "a", 2500, 0, 45, Worktype.Outsource);
v32.FromWhichEmployer = e3;

Employers.Add(e1);
Employers.Add(e2);
Employers.Add(e3);

e1.AddVacancy(v12);
e1.AddVacancy(v11);
e2.AddVacancy(v22);
e2.AddVacancy(v21);
e3.AddVacancy(v31);
e3.AddVacancy(v32);

List<Vacancy> vs1 = new();
List<Vacancy> vs2 = new();
List<Vacancy> vs3 = new();

vs1.Add(v12);
vs1.Add(v11);
vs2.Add(v21);
vs2.Add(v22);
vs3.Add(v31);
vs3.Add(v32);

e1.Vacancies = vs1;
e2.Vacancies = vs2;
e3.Vacancies = vs3;

#endregion

void addNewWorkerToFIle()
{
    List<Worker>? workers = null;
    var json = File.ReadAllText("Workers.json");
    workers = JsonSerializer.Deserialize<List<Worker>>(json);

    workers.Add(Worker.AddWorker());

    var json1 = JsonSerializer.Serialize(workers);
    File.WriteAllText("Workers.json", json);

    Console.WriteLine("Worker added file succesfully!");
    Thread.Sleep(1000);
    Console.Clear();
}

void addNewEmployerToFIle()
{
    List<Employer>? employers = null;
    var json = File.ReadAllText("Employers.json");
    employers = JsonSerializer.Deserialize<List<Employer>>(json);

    employers.Add(Employer.CreateEmployer());

    var json1 = JsonSerializer.Serialize(employers);
    File.WriteAllText("Employers.json", json);

    Console.WriteLine("Employer added file succesfully!");
    Thread.Sleep(1000);
    Console.Clear();
}


bool WorkerSignIn()
{
    while (true)
    {
        string name, password;
        Console.WriteLine("Insert name: ");
        name = Console.ReadLine();

        Console.WriteLine("Insert password: ");
        password = Console.ReadLine();

        List<Worker>? WorkersFromFile = null;
        var json = File.ReadAllText("Workers.json");
        WorkersFromFile = JsonSerializer.Deserialize<List<Worker>>(json);

        foreach (var item in WorkersFromFile)
        {
            if (item.Name == name || item.Password == password)
            {
                Console.WriteLine("Signed in succesfully:");
                Thread.Sleep(1000);
                Console.Clear();
                return true;
            }
        }
        return false;
    }
}

Employer GetEmployerFromFile(string empname, string emppassword)
{
    while (true)
    {
        List<Employer>? EmployersFromFile = null;
        var json = File.ReadAllText("Employers.json");
        EmployersFromFile = JsonSerializer.Deserialize<List<Employer>>(json);

        foreach (var item in EmployersFromFile)
        {
            if (item.Name == empname || item.Password == emppassword)
            {
                return item;
            }
        }
        return null;
    }
}

bool EmployerIsExistInFile(string empname, string emppassword)
{
    while (true)
    {
        List<Employer>? EmployersFromFile = null;
        var json = File.ReadAllText("Employers.json");
        EmployersFromFile = JsonSerializer.Deserialize<List<Employer>>(json);

        foreach (var item in EmployersFromFile)
        {
            if (item.Name == empname || item.Password == emppassword)
            {
                Console.WriteLine("Signed in succesfully:");
                Thread.Sleep(1000);
                Console.Clear();
                return true;
            }
        }
        return false;
    }
}


//ilk ishlet bunu ki vacansiyalar liste yigilsin
void FillListWithAllVacancies()
{
    foreach (var item in Employers)
    {
        foreach (var item1 in item.Vacancies)
        {
            AllVacancies.Add(item1);
        }
    }
}


void ShowAnyVacancyList(List<Vacancy> list)
{
    foreach (var item in list)
    {
        Console.WriteLine(item);
    }
}



//worker
void apply(string title, string content, Worker worker)
{
    int id;
    Console.WriteLine("Id:");
    id = Convert.ToInt32(Console.ReadLine());

    foreach (var item in Employers)
    {
        foreach (var vacancy in item.Vacancies)
        {
            if (vacancy.ObjectId == id)
            {
                //item.Notifications.Where(n => n.Vacancy == vacancy);
                item.Notifications.Add(new Notification(title, content, worker, vacancy));
            }
        }
    }
}

void FilterVacancies()
{
    List<Vacancy> vacanciesForFilter = AllVacancies;

    bool exit = false;

    while (!exit)
    {
        try
        {
            int choice;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("1)FilterVacancieByAge\n2)FilterVacancieByName\n3)FilterVacancieByExperience\n4)FilterVacancieBySalary\n5)FilterVacancieByWorkType\n6)Exit\n");
            choice = Convert.ToInt32(Console.ReadLine());
            Console.ResetColor();

            switch (choice)
            {
                case 1:
                    sbyte maxAge;
                    Console.WriteLine("Insert maximum age: ");
                    maxAge = Convert.ToSByte(Console.ReadLine());
                    vacanciesForFilter = Filter.FilterVacancieByAge(vacanciesForFilter, maxAge);
                    Console.Clear();
                    break;
                case 2:
                    string? jobName;
                    Console.WriteLine("Insert Job name: ");
                    jobName = Console.ReadLine();
                    vacanciesForFilter = Filter.FilterVacancieByName(vacanciesForFilter, jobName);
                    break;
                case 3:
                    sbyte experience;
                    Console.WriteLine("Insert minumum experience: ");
                    experience = Convert.ToSByte(Console.ReadLine());
                    vacanciesForFilter = Filter.FilterVacancieByExperience(vacanciesForFilter, experience);
                    break;
                case 4:
                    double minSalary;
                    Console.WriteLine("Insert minumum Salary: ");
                    minSalary = Convert.ToDouble(Console.ReadLine());
                    vacanciesForFilter = Filter.FilterVacancieBySalary(vacanciesForFilter, minSalary);
                    break;

                case 5:
                    Worktype wt;
                    Console.Write("Insert worktype 1)Fulltime 2)Part-time 3)Freelance 4)Remoute 5)Outsource: ");
                    int choice2 = Convert.ToInt32(Console.ReadLine());

                    switch (choice2)
                    {
                        case 1:
                            wt = Worktype.Fulltime;
                            break;
                        case 2:
                            wt = Worktype.Parttime;
                            break;
                        case 3:
                            wt = Worktype.Freelance;
                            break;
                        case 4:
                            wt = Worktype.Remoute;
                            break;
                        case 5:
                            wt = Worktype.Outsource;
                            break;
                        default:
                            continue;
                    }

                    vacanciesForFilter = Filter.FilterVacancieByWorkType(vacanciesForFilter, wt);
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Choose one of them!");
                    Thread.Sleep(1000);
                    continue;
            }

            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine();

            ShowAnyVacancyList(vacanciesForFilter);
            Console.ResetColor();
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
            Console.ReadKey();
            continue;
        }
    }
}


//FillListWithAllVacancies();

//FilterVacancies();

while (true)
{
    int ch2;
    Console.WriteLine("1)Employer 2)Worker 3)Exit");
    ch2 = Convert.ToInt32(Console.ReadLine());

    if (ch2 == 1)
    {
        while (true)
        {
            Console.WriteLine("1)Sign up\n2)Sign in\n3)Exit\n");
            ch2 = Convert.ToInt32(Console.ReadLine());

            if (ch2 == 1)
            {
                addNewEmployerToFIle();
                continue;
            }
            else if (ch2 == 2)
            {
                string name, password;
                Console.WriteLine("Insert name: ");
                name = Console.ReadLine();

                Console.WriteLine("Insert password: ");
                password = Console.ReadLine();

                if (EmployerIsExistInFile(name, password))
                {
                    Employer Item = GetEmployerFromFile(name, password);
                    while (true)
                    {
                        Console.WriteLine("1)Show all vacancies\n2)Show all Notifications\n");
                        ch2 = Convert.ToInt32(Console.ReadLine());

                        if (ch2 == 1)
                        {
                            Console.WriteLine("1)Add Vacancy\n2)Delete Vacancy\n");
                            ch2 = Convert.ToInt32(Console.ReadLine());
                            if (ch2 == 1)
                            {
                                Item.AddVacancy(Vacancy.CreateVacancy());
                                Console.WriteLine("Vacancy added succesfully!");
                            }
                            else if (ch2 == 2)
                            {
                                int id;
                                Console.WriteLine("Insert id:");
                                id = Convert.ToInt32(Console.ReadLine());
                                Item.DeleteVacancy(id);
                            }
                            else
                            {
                                Console.WriteLine("Choose one of them!");
                                Console.ReadKey();
                                Console.Clear();
                            }
                        }

                        //Show all Notifications
                        //Delete Notification
                        //Accept Notification
                        //reject Notification
                        //Filter cv by index
                    }
                }
                else
                {
                    Console.WriteLine("Employer cant found !");
                    Thread.Sleep(1000);
                    Console.Clear();
                    continue;
                }
            }
            else if (ch2 == 3) break;
            else continue;
        }
    }

    else if (ch2 == 2)
    {
        while (true)
        {
            Console.WriteLine("1)Sign up\n2)Sign in\n3)Exit\n");
            ch2 = Convert.ToInt32(Console.ReadLine());

            if (ch2 == 1)
            {
                addNewWorkerToFIle();
                continue;
            }
            else if (ch2 == 2)
            {
                if (WorkerSignIn())
                {
                    //Workerin ishleri

                }
                else
                {
                    Console.WriteLine("Worker cant found !");
                    Thread.Sleep(1000);
                    Console.Clear();
                    continue;
                }
            }
            else if (ch2 == 3) break;
            else continue;
        }
    }
    else
    {
        Console.WriteLine("Choose one of them!");
        continue;
    }
}