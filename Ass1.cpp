#include<bits/stdc++.h>
using namespace std;

int Dept_no=0,Emp_no=0;
char DeptName[50], DeptManager[50], DeptCursor[5], DeptID[30], DeptSiz[5];
char EmpName[50], Emp_id[13], EmpCursor[5],Emp_Dept_id[30],Emp_position[50], EmpSiz[5];
int header = -1, Empheader=-1;

struct Employee
{
    char ID[13];
    char Name[50];
    char Dept_id[30];
    char position[50];
    int Esiz;
};
struct Department
{
    char id [30];
    char name [50];
    char manager [50];
    int Dsiz;
};
struct Emp_PriIndex
{
    char ID[13], offset[10];
}E_in[200], E_temp;
struct Emp_SecIndex
{
    char Dept_id[30],ID[13];
}E_SIn[100], E_stemp;
struct DeptPriIndex
{
    char id[30], ind[10];
}in[200], temp;
struct DeptSecIndex
{
    char name[50],id[30];
}SIn[100], stemp;
void readHeader()
{
    fstream HFile;
    HFile.open("header.txt", ios::in);
    HFile >> header;
    HFile.close();
}
void writeHeader(int header)
{
    fstream HFile;
    HFile.open("header.txt", ios::out);
    HFile << header;
    HFile.close();
}
void readEmpHeader()
{
    fstream HFile;
    HFile.open("employeeheader.txt", ios::in);
    HFile >> Empheader;
    HFile.close();
}
void writeEmpHeader(int header)
{
    fstream HFile;
    HFile.open("employeeheader.txt", ios::out);
    HFile << header;
    HFile.close();
}
void Emp_readRecNo()
{
    fstream nFile;
    nFile.open("EMP_no.txt", ios::in);
    nFile >> Emp_no;
    nFile.close();
}
void Emp_writeRecNo()
{
    fstream nFile;
    nFile.open("Emp_no.txt", ios::out);
    nFile << Emp_no;
    nFile.close();
}
void readRecNo()
{
    fstream nFile;
    nFile.open("no.txt", ios::in);
    nFile >> Dept_no;
    nFile.close();
}
void writeRecNo()
{
    fstream nFile;
    nFile.open("no.txt", ios::out);
    nFile << Dept_no;
    nFile.close();
}
void createEmpPriIndex()
{
    int curent =0;
    fstream file;
    file.open("Emp_data.txt", ios::in);
    for (int i=0; i<Emp_no; i++)
    {
        file.getline(EmpSiz, 5, '|');
        file.getline(EmpName, 50, '|');
        file.getline(Emp_id, 13, '|');
        file.getline(Emp_position, 50, '|');
        file.getline(Emp_Dept_id, 30, '\n');

        itoa(curent, EmpCursor, 10);

        strcpy_s(E_in[i].ID, Emp_id);

        strcpy_s(E_in[i].offset, EmpCursor);

        curent+=atoi(EmpSiz);
    }
    file.close();
}
void createDeptPriIndex()
{
    int curent =0;
    fstream file1;
    file1.open("data.txt", ios::in);
    for (int i=0; i<Dept_no; i++)
    {
        file1.getline(DeptSiz, 5, '|');
        file1.getline(DeptID, 30, '|');
        file1.getline(DeptName, 50, '|');
        file1.getline(DeptManager, 50, '\n');

        itoa(curent, DeptCursor, 10);

        strcpy_s(in[i].id, DeptID);

        strcpy_s(in[i].ind, DeptCursor);

        curent+=atoi(DeptSiz);
    }
    file1.close();
}
void readEmpPriIndex()
{
    Emp_readRecNo();
    fstream f;
    f.open("Emp_index.txt", ios::in);
    for(int i=0; i<Emp_no; i++)
    {
        f.getline(E_in[i].ID, 13, '|');
        f.getline(E_in[i].offset, 10, '\n');
    }
}
void readDeptPriIndex()
{
    readRecNo();
    fstream ff;
    ff.open("index.txt", ios::in);
    for(int i=0; i<Dept_no; i++)
    {
        ff.getline(in[i].id, 30, '|');
        ff.getline(in[i].ind, 10, '\n');
    }
    ff.close();
}
void writeEmpPriIndex()
{
    Emp_readRecNo();
    fstream file;
    file.open("Emp_index.txt", ios::out);
    for (int i = 0; i <Emp_no; i++)
    {
        file << E_in[i].ID << "|" << E_in[i].offset << "\n";
    }
}
void writeDeptPriIndex()
{
    readRecNo();
    fstream file2;
    file2.open("index.txt", ios::out);
    for (int i=0; i<Dept_no; i++)
    {
        file2 << in[i].id << "|" << in[i].ind << "\n";

    }
    file2.close();
}
void createDeptSecIndex()
{
    fstream recordFile;
    recordFile.open("data.txt", ios::in);
    for (int i=0; i<Dept_no; i++)
    {

        recordFile.getline(DeptSiz, 5, '|');
        recordFile.getline(DeptID, 30, '|');
        recordFile.getline(DeptName, 50, '|');
        recordFile.getline(DeptManager, 50, '\n');



        strcpy_s(SIn[i].name, DeptName);

        strcpy_s(SIn[i].id, DeptID);

    }
    recordFile.close();

}
void createEmpSecIndex()
{
    fstream Record;
    Record.open("Emp_data.txt", ios::in);
    for (int i=0; i<Emp_no; i++)
    {

        Record.getline(EmpSiz, 5, '|');
        Record.getline(EmpName, 50, '|');
        Record.getline(Emp_id, 13, '|');
        Record.getline(Emp_position, 50, '|');
        Record.getline(Emp_Dept_id, 30, '\n');



        strcpy_s(E_SIn[i].Dept_id, Emp_Dept_id);

        strcpy_s(E_SIn[i].ID, Emp_id);

    }
    Record.close();

}
void writeEmpSecIndex()
{
    fstream Sec;
    Sec.open("Emp_Secondry.txt", ios::out);
    for (int i=0; i<Emp_no; i++)
    {
        Sec << E_SIn[i].Dept_id << "|" << E_SIn[i].ID << "\n";
    }
    Sec.close();
}
void writeDeptSecIndex()
{
    fstream SIndexFile;
    SIndexFile.open("Secindex.txt", ios::out);
    for (int i=0; i<Dept_no; i++)
    {
        SIndexFile << SIn[i].name << "|" << SIn[i].id << "\n";
    }
    SIndexFile.close();
}
void readEmpSecIndex()
{
    fstream s;
    s.open("Emp_Secondry.txt", ios::in);

    int i = 0;
    while (!s.eof())
    {
        s.getline(E_SIn[i].Dept_id, 30, '|');
        s.getline(E_SIn[i].ID, 13, '\n');
        i++;
    }
    s.close();
}
void readDeptSecIndex()
{
    readRecNo();
    fstream ff;
    ff.open("Secindex.txt", ios::in);

    for(int i=0; i<Dept_no; i++)
    {
        ff.getline(SIn[i].name, 50, '|');
        ff.getline(SIn[i].id, 30, '\n');

    }
    ff.close();
}
void sortEmpPriIndex()
{
    int i, j;
    for (i = 0;i < Emp_no - 1;i++)
    {
        for (j = 0;j < Emp_no - i - 1;j++)
        {
            if (strcmp(E_in[j].ID, E_in[j + 1].ID) > 0)
            {
                E_temp = E_in[j];
                E_in[j] = E_in[j + 1];
                E_in[j + 1] = E_temp;
            }
        }

    }

}
void sortDeptPriIndex()
{
    int i, j;
    for (i = 0;i < Dept_no - 1;i++)
    {
        for (j = 0;j < Dept_no - i - 1;j++)
        {
            if (strcmp(in[j].id, in[j + 1].id) > 0)
            {
                temp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = temp;
            }
        }

    }

}
void sortEmpSecIndex()
{
    int i, j;
    for (i = 0;i < Emp_no - 1;i++)
    {
        for (j = 0;j < Emp_no - i - 1;j++)
        {
            if (strcmp(E_SIn[j].Dept_id, E_SIn[j + 1].Dept_id) > 0)
            {
                E_stemp = E_SIn[j];
                E_SIn[j] = E_SIn[j + 1];
                E_SIn[j + 1] = E_stemp;
            }
        }

    }

}
void sortDeptSecIndex()
{
    int i, j;
    for (i = 0;i < Dept_no - 1;i++)
    {
        for (j = 0;j < Dept_no - i - 1;j++)
        {
            if (strcmp(SIn[j].name, SIn[j + 1].name) > 0)
            {
                stemp = SIn[j];
                SIn[j] = SIn[j + 1];
                SIn[j + 1] = stemp;
            }
        }

    }

}
int AddEmployee()
{
    fstream Record;
     Employee E;

    cout<<"Enter Employee Name: ";
    cin>>E.Name;

    cout<<"Enter Employee ID: ";
    cin>>E.ID;

    cout<<"Enter position: ";
    cin>>E.position;
    cout<<"Enter Employee Dapart_id: ";
    cin>>E.Dept_id;

    E.Esiz=0;
    E.Esiz += strlen(E.Name);
    E.Esiz += strlen(E.ID);
    E.Esiz += strlen(E.position);
    E.Esiz += strlen(E.Dept_id);
    E.Esiz+=5;
    char s[5];
    itoa(E.Esiz,s,10);

    E.Esiz+=strlen(s);

    Record.open("Emp_data.txt", ios::app | ios::out);
    Record << E.Esiz<< "|" << E.Name  << "|" << E.ID << "|" << E.position << "|" << E.Dept_id<< "\n";
    Record.close();

    //********************************************
    Emp_readRecNo();

    Emp_no++;

    Emp_writeRecNo();
    //***********************************************
    createEmpPriIndex();

    sortEmpPriIndex();

    writeEmpPriIndex();

//*******************************************************************************

    createEmpSecIndex();

    sortEmpSecIndex();

    writeEmpSecIndex();
}
int AddDepartment()
{
    fstream recordFile;
    Department dept;

    cout<<"Enter Name: ";
    cin>>dept.name;

    cout<<"Enter ID: ";
    cin>>dept.id;

    cout<<"Enter Manager: ";
    cin>>dept.manager;


    dept.Dsiz=0;
    dept.Dsiz += strlen(dept.name);
    dept.Dsiz += strlen(dept.id);
    dept.Dsiz += strlen(dept.manager);
    dept.Dsiz+=4;
    char s[5];
    itoa(dept.Dsiz,s,10);

    dept.Dsiz+=strlen(s);

    recordFile.open("data.txt", ios::app | ios::out);
    recordFile << dept.Dsiz<< "|" << dept.id << "|" << dept.name << "|" << dept.manager << "\n";
    recordFile.close();

    //********************************************
    readRecNo();

    Dept_no++;

    writeRecNo();
    //***********************************************
    createDeptPriIndex();

    sortDeptPriIndex();

    writeDeptPriIndex();

//*******************************************************************************

    createDeptSecIndex();

    sortDeptSecIndex();

    writeDeptSecIndex();
}
void Emp_retrive_record(char* offset)
{
    int x =atoi(offset);
    fstream ff;
    ff.open("Emp_data.txt", ios::in);
    ff.seekg(x,ios::beg);
    ff.getline(offset, 10, '|');
    ff.getline(EmpName, 50, '|');
    ff.getline(Emp_id, 13, '|');
    ff.getline(Emp_position, 50, '|');
    ff.getline(Emp_Dept_id, 30, '\n');

    cout<<'\n'<<"Name   ID    Position   DeptiD "<<endl;
    cout<<EmpName<<"    "<<Emp_id<<"    "<<Emp_position<<"    "<<Emp_Dept_id<<'\n'<<endl;
    ff.close();
}
void retrive_record(char* ind)
{
    int x =atoi(ind);
    fstream ff;
    ff.open("data.txt", ios::in);
    ff.seekg(x,ios::beg);
    ff.getline(ind, 10, '|');
    ff.getline(DeptID, 30, '|');
    ff.getline(DeptName, 50, '|');
    ff.getline(DeptManager, 50, '\n');

    cout<<'\n'<<"ID    Name    Manager"<<endl;
    cout<<DeptID<<"    "<<DeptName<<"    "<<DeptManager<<'\n'<<endl;
    ff.close();
}
char * SearchEmployee_By_id(char* id, int low, int high)
{
    int mid;
    while(low<high)
    {
        mid = (low+high)/2;
        if (strcmp(E_in[mid].ID, id) == 0)
        {
            return E_in[mid].offset;
        }
        if(strcmp(E_in[mid].ID, id) > 0)
        {
            return SearchEmployee_By_id(id, low, mid);
        }
        if(strcmp(E_in[mid].ID, id) < 0)
        {
            return SearchEmployee_By_id(id, mid+1, high);
        }

    }
    return NULL;
}
char * SearchDepartment(char* id, int low, int high)
{
    int mid;
    while(low<high)
    {
        mid = (low+high)/2;
        if (strcmp(in[mid].id, id) == 0)
        {
            return in[mid].ind;
        }
        if(strcmp(in[mid].id, id) > 0)
        {
            return SearchDepartment(id, low, mid);
        }
        if(strcmp(in[mid].id, id) < 0)
        {
            return SearchDepartment(id, mid+1, high);
        }

    }
    return NULL;
}
void deleteEmpFromDataFile(char* st_id)
{
    readEmpHeader();
    int x =atoi(st_id);
    fstream ff;
    ff.open("Emp_data.txt");
    ff.seekp(x, ios::beg);
     ff<<'*'<<Empheader<<'|';
    ff.close();
}
void deleteDeptFromDataFile(char* ind)
{
    readHeader();
    int x =atoi(ind);
    fstream ff;
    ff.open("data.txt");
    ff.seekp(x, ios::beg);
    ff<<'*'<<header<<'|';
    ff.close();
}
void deleteEmpFromPriIndex(char* id)
{
    Emp_readRecNo();
    readEmpPriIndex();
    for(int i=0; i<Emp_no; i++)
    {
        if(strcmp(E_in[i].ID, id)==0)
        {
            int h = atoi(E_in[i].offset);
            writeEmpHeader(h);
            Emp_no--;
            for(int j = i; j<Emp_no; j++)
            {
                strcpy(E_in[j].ID, E_in[j+1].ID);
                strcpy(E_in[j].offset, E_in[j+1].offset);
            }
        }
    }
    Emp_writeRecNo();
    writeEmpPriIndex();
}
void deleteDeptFromPriIndex(char* id)
{
    readRecNo();
    readDeptPriIndex();
    for(int i=0; i<Dept_no; i++)
    {
        if(strcmp(in[i].id, id)==0)
        {
            int h = atoi(in[i].ind);
            writeHeader(h);
            Dept_no--;
            for(int j = i; j<Dept_no; j++)
            {
                strcpy(in[j].id, in[j+1].id);
                strcpy(in[j].ind, in[j+1].ind);
            }
        }
    }
    writeRecNo();
    writeDeptPriIndex();
}
void deleteEmployee()
{
    Emp_readRecNo();
    readEmpPriIndex();
    cout<<"Enter the id: ";
    cin>>Emp_id;
    if (SearchEmployee_By_id(Emp_id,0,Emp_no)!=NULL)
    {
        deleteEmpFromDataFile(SearchEmployee_By_id(Emp_id,0,Emp_no));

        deleteEmpFromPriIndex(Emp_id);
        cout<<"Deleted Successfully"<<endl;
        return;
    }
    cout << "Deletion failed record not found"<<endl;
}
void deleteDepartment()
{
    readRecNo();
    readDeptPriIndex();
    cout<<"Enter the id: ";
    cin>>DeptID;
    if (SearchDepartment(DeptID,0,Dept_no)!=NULL)
    {
        deleteDeptFromDataFile(SearchDepartment(DeptID,0,Dept_no));

        deleteDeptFromPriIndex(DeptID);
        cout<<"Deleted Successfully"<<endl;
        return;
    }
    cout << "deletion failed record not found\n";
}
char * SeachEmployeetByDeptid(char * Deptid,int low,int high)
{
    bool flag=false;
    for(int i=0; i<Emp_no; i++)
    {
        if(strcmp(E_SIn[i].Dept_id, Deptid) == 0)
        {
            flag = true;
            Emp_retrive_record(SearchEmployee_By_id(E_SIn[i].ID,0,Emp_no));
        }
    }
    if(!flag)
    {
        return NULL;
    }
    else
    {
        return Deptid;
    }
}
char * SeachDepartmentByName (char * name,int low,int high)
{
    int mid;
    while(low<high)
    {
        mid = (high + low)/2;
        if(strcmp(SIn[mid].name, name) == 0)
        {
            return SIn[mid].id;
        }
        if(strcmp(SIn[mid].name, name) > 0)
        {
            return SeachDepartmentByName(name,low,mid);
        }
        if(strcmp(SIn[mid].name, name) < 0)
        {
            return SeachDepartmentByName(name,mid+1,high);
        }
    }
    return NULL;
}
void PrintEmptByDeptid()
{
    readEmpSecIndex();
    readEmpPriIndex();

    cout<<"Enter the Dept ID: ";
    cin>>Emp_Dept_id;
    char * id = SeachEmployeetByDeptid(Emp_Dept_id,0,Emp_no);
    if(id==NULL)
    {
        cout<<"DeptID not found"<<endl;
        return;
    }
}

void PrintDeptByName()
{
    readDeptSecIndex();
    readDeptPriIndex();


    cout<<"Enter the name: ";
    cin>>DeptName;
    char * id = SeachDepartmentByName(DeptName,0,Dept_no);
    cout<<id;
    if(id!= nullptr)
    {
        if(SearchDepartment(id,0,Dept_no) != nullptr)
        {
            retrive_record(SearchDepartment(SeachDepartmentByName(DeptName,0,Dept_no),0,Dept_no));
            return;
        }
    }
    cout<<"Department not found"<<endl;
    return;
}
void PrintDeptByID()
{
    readDeptPriIndex();
    cout<<"Enter the id: ";
    cin>>DeptID;
    if(SearchDepartment(DeptID,0,Dept_no) != NULL)
    {
        retrive_record(SearchDepartment(DeptID,0,Dept_no));
        return;
    }
    cout<<"Department not found"<<endl;
    return;
}
void PrintEmpByID()
{
    readEmpPriIndex();
    cout<<"Enter the id: ";
    cin>>Emp_id;
    if(SearchEmployee_By_id(Emp_id,0,Emp_no) != NULL)
    {
        Emp_retrive_record(SearchEmployee_By_id(Emp_id,0,Emp_no));
        return;
    }
    cout<<"Employee not found"<<endl;
    return ;
}
void writeQuery(string query)
{
     query=to_lower(query);
    char ch[13];
    string q=(query);
    if(q=="select all employee where dept_id")
    {
        cout<<"Enter dept_id ";
        cin>>ch;
        Emp_retrive_record(SeachEmployeetByDeptid(ch,0,Emp_no));
    }
    else if(q=="select all employee where employee_id")
    {
        cout<<"Enter Employee_id ";
        cin>>ch;
        Emp_retrive_record(SearchEmployee_By_id(ch,0,Emp_no));
    }
    else if(q=="select all department where dept_id")
    {
        cout<<"Enter dept_id ";
        cin>>ch;
        retrive_record(SearchDepartment(ch,0,Dept_no));
    }
    else if(q=="select all department where dept_name")
    {
        cout<<"Enter dept_name ";
        cin>>ch;
        retrive_record(SeachDepartmentByName(ch,0,Dept_no));
    }
    else
    {
        cout<<"wrong Query";
    }

}



int main()
{
    int choice;
    string q;
    do
    {
        cout<<"Main Menu:"<<endl
            <<"1.Add New Employee"<<endl
            <<"2.Add New Department"<<endl
            <<"3.Delete Employee"<<endl
            <<"4.Delete Department"<<endl
            <<"5.Print Employee"<<endl
            <<"6.Print Department's Employee"<<endl
            <<"7.Print Department by ID"<<endl
            <<"8.Print Department by Name"<<endl
            <<"9.Write a Query"<<endl
            <<"10.Exit"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
              AddEmployee();
              break;
            }
            case 2:
            {
                AddDepartment();
                break;
            }
            case 3:
            {
              deleteEmployee();
              break;
            }
            case 4:
            {
                deleteDepartment();
                break;
            }
            case 5:
            {
                PrintEmpByID();
                break;
            }
            case 6:
            {
                PrintEmptByDeptid();
                break;
            }
            case 7:
            {
                PrintDeptByID();
                break;
            }
            case 8:
            {
                PrintDeptByName();
                break;
            }
            case 9:
            {
                
                cout<<"Enter Query";
                cin>>q;
                writeQuery(q);
                break;
            }

        }
    }
    while(choice!=10);


    return 0;
}
