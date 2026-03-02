#include <iostream>
#include <fstream>
using namespace std;

struct Customer;
struct Service;
int tutup = 0;

struct Customer
{
    string nama, gender, telepon, alamat, umur;
    Customer *next;
    Customer *prev;
    Service *headServ;
};

struct Service
{
    string tipeMobil, merekMobil, kendala, namaMontir;
    Customer *dataCust;
    Service *allnext;
    Service *next;
    Service *prev;
};

Customer *headCust = NULL;
Customer *tailCust = NULL;
Service *servHistory = NULL;
string nama;

void dataBaru()
{
    system("cls");

    Service *servBaru = new Service();

    cout << "====== Input Data Service ======" << endl;
    cout << "Tipe Mobil: ";
    getline(cin, servBaru -> tipeMobil);
    cout << "Merek Mobil: ";
    getline(cin, servBaru -> merekMobil);
    cout << "Kendala: ";
    getline(cin, servBaru -> kendala);
    cout << "Nama Montir | Suby | Farhan | Dimas | Aldo |: ";
    getline(cin, servBaru -> namaMontir);
    cout << "Nama Customer: ";
    getline(cin, nama);

    Customer *that = headCust;

    while (that != NULL)
    {
        if (that -> nama == nama)
            break;
        that = that -> next;
    }

    if (that == NULL)
    {

        Customer *custBaru = new Customer();

        cout << "Nomor Telepon: ";
        getline(cin, custBaru -> telepon);
        cout << "Alamat: ";
        getline(cin, custBaru -> alamat);
        cout << "Umur: ";
        getline(cin, custBaru -> umur);
        cout << "Gender: ";
        getline(cin, custBaru -> gender);

        if (headCust == NULL)
        {
            custBaru -> next = NULL;
            custBaru -> headServ = NULL;
            headCust = tailCust = custBaru;
        }
        else
        {
            custBaru  ->  prev;
            tailCust  ->  next = custBaru;
            tailCust = custBaru;
        }

        tailCust  ->  headServ = servBaru;
        servBaru  ->  dataCust = tailCust;

        ofstream fileCust("Customer.txt", ios::app);
        fileCust << nama << endl
                 << custBaru -> telepon << endl
                 << custBaru -> alamat << endl
                 << custBaru -> umur << endl
                 << custBaru -> gender << endl;
        fileCust.close();

        cout << endl << "*Pelanggan baru telah terdaftar dan servis berhasil dicatat*" << endl;
        system("pause");
    }
    else
    {

        servBaru  ->  next = that  ->  headServ;
        that  ->  headServ = servBaru;
        servBaru  ->  dataCust = that;

        cout << endl << "*Pelanggan sudah terdaftar sebelumnya dan servis berhasil dicatat*" << endl;
        system("pause");
    }

    ofstream fileServ("Service.txt", ios::app);
    fileServ << nama << endl
             << servBaru -> tipeMobil << endl
             << servBaru -> merekMobil << endl
             << servBaru -> kendala << endl
             << servBaru -> namaMontir << endl;
    fileServ.close();
}

void allCust()
{
    system("cls");
    Customer *that = headCust;
    cout << "====== All Customers ======" << endl;
    while (that != NULL)
    {
        cout << "Nama: " << that -> nama << endl
             << "Nomor Telepon: " << that -> telepon << endl
             << "Alamat: " << that -> alamat << endl
             << "==== Service Terakhir ====" << endl;
        Service *serv = that -> headServ;
        
            cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                 << "Merek Mobil: " << serv -> merekMobil << endl
                 << "Kendala: " << serv -> kendala << endl
                 << "Nama Montir: " << serv -> namaMontir << endl;
            serv = serv -> next;
        
        cout << "-----------------------------" << endl;
        that = that -> next;
    }
    system("pause");
}

void singleCust()
{
    system("cls");
    char pil;
    Customer *that = headCust;
    while (that != NULL)
    {
        cout << "====== Customer Data ======" << endl
             << "Nama: " << that -> nama << endl
             << "Nomor Telepon: " << that -> telepon << endl
             << "Umur: " << that -> umur << endl
             << "Alamat: " << that -> alamat << endl
             << "Gender: " << that -> gender << endl
             << "==== 3 Service Terakhir ====" << endl;

        Service *serv = that -> headServ;
        int count = 0;
        while (serv != NULL && count < 3)
        {
            cout << "Mobil: " << serv -> merekMobil << endl
                 << "Kendala: " << serv -> kendala << endl
                 << "Montir: " << serv -> namaMontir << endl
                 << "-----------------------------" << endl;
            serv = serv -> next;
            count++;
        }
        cout << "[N]ext, [P]revious, [E]xit: " << endl << "Pilihan: ";
        cin >> pil;
        if (pil == 'N' || pil == 'n')
        {
            if (that -> next != NULL)
            {
                system("cls");
                that = that -> next;
            }
            else
            {
                system("cls");                
                that = headCust;
            }
            
        }
        else if (pil == 'P' || pil == 'p')
        {
            if (that -> prev != NULL)
            {
                system("cls");
                that = that -> prev;
            }
            else
            {
                system("cls");
                that = tailCust;
            }
            
        }
        else if (pil == 'E' || pil == 'e')
        {
            break;
        }
    }
}

void allServ()
{
    system("cls");
    Service *serv = servHistory;
    cout << "====== All Services ======" << endl;
    while (serv != NULL)
    {
        cout << "Tipe Mobil: " << serv -> tipeMobil << endl
             << "Merek Mobil: " << serv -> merekMobil << endl
             << "Kendala: " << serv -> kendala << endl
             << "Nama Montir: " << serv -> namaMontir << endl
             << "Nama Customer: " << serv -> dataCust -> nama << endl
             << "Nomor Telepon Customer: " << serv -> dataCust -> telepon << endl
             << "-----------------------------" << endl;
        serv = serv -> allnext;
    }
    system("pause");
}

void mechanicHistory()
{
    system("cls");
    int pil;
    cout << "====== Mechanic's Job History ======" << endl
    << "Pilih Menu: " << endl << endl
    << "1. Suby" << endl
    << "2. Farhan" << endl 
    << "3. Dimas" << endl
    << "4. Aldo" << endl << endl
    << "Pilihan: ";
    cin >> pil;
    
    if (pil == 1)
    {
        cout << endl << "====== Suby's Job ======" << endl;
        Customer *that = headCust;
        while (that != NULL)
        {
            Service *serv = that -> headServ;
            while (serv != NULL)
            {
                if (serv -> namaMontir == "Suby")
                {
                    cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                         << "Merek Mobil: " << serv -> merekMobil << endl
                         << "Kendala: " << serv -> kendala << endl
                         << "Nama Montir: " << serv -> namaMontir << endl
                         << "Nama Customer: " << that -> nama << endl
                         << "Nomor Telepon Customer: " << that -> telepon << endl
                         << "-----------------------------" << endl;
                }
                serv = serv -> next;
            }
            that = that -> next;
        }
        system("pause");
    }
    else if (pil == 2)
    {
        cout << endl <<"====== Farhan's Job ======" << endl;
        Customer *that = headCust;
        while (that != NULL)
        {
            Service *serv = that -> headServ;
            while (serv != NULL)
            {
                if (serv -> namaMontir == "Farhan")
                {
                    cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                         << "Merek Mobil: " << serv -> merekMobil << endl
                         << "Kendala: " << serv -> kendala << endl
                         << "Nama Montir: " << serv -> namaMontir << endl
                         << "Nama Customer: " << that -> nama << endl
                         << "Nomor Telepon Customer: " << that -> telepon << endl
                         << "-----------------------------" << endl;
                }
                serv = serv -> next;
            }
            that = that -> next;
        }
        system("pause");
    }
    else if (pil == 3)
    {
        cout << endl << "====== Dimas's Job ======" << endl;
        Customer *that = headCust;
        while (that != NULL)
        {
            Service *serv = that -> headServ;
            while (serv != NULL)
            {
                if (serv -> namaMontir == "Dimas")
                {

                        cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                             << "Merek Mobil: " << serv -> merekMobil << endl
                             << "Kendala: " << serv -> kendala << endl
                             << "Nama Montir: " << serv -> namaMontir << endl
                             << "Nama Customer: " << that -> nama << endl
                             << "Nomor Telepon Customer: " << that -> telepon << endl
                             << "-----------------------------" << endl;
                }serv = serv -> next;
            }
            that = that -> next;
        }
        system("pause");
    }
    else if (pil == 4)
    {
        cout << endl << "====== Aldo's Job ======" << endl;
        Customer *that = headCust;
        while (that != NULL)
        {
            Service *serv = that -> headServ;
            while (serv != NULL)
            {
                if (serv -> namaMontir == "Aldo")
                {
                        cout << "Tipe Mobil: " << serv -> tipeMobil << endl
                             << "Merek Mobil: " << serv -> merekMobil << endl
                             << "Kendala: " << serv -> kendala << endl
                             << "Nama Montir: " << serv -> namaMontir << endl
                             << "Nama Customer: " << that -> nama << endl
                             << "Nomor Telepon Customer: " << that -> telepon << endl
                             << "-----------------------------" << endl;     
                }
                serv = serv -> next;
            }
            that = that -> next;
        }
        system("pause");
    }
}

void serviceMenu()
{
    system("cls");
    int pil;
    cout << "====== Services ======" << endl
    << "Pilih Menu: " << endl << endl
    << "1. Semua Service Singkat" << endl
    << "2. Service Baru" << endl 
    << "3. Riwayat Kerja Montir" << endl << endl
    << "Pilihan: ";
    cin >> pil;
    cin.ignore();

    if (pil == 1)
    {
        allServ();
    }
    else if (pil == 2)
    {
        dataBaru();
    }
    else if (pil == 3)
    {
        mechanicHistory();
    }
}

void Menu()
{
    int pil;
    system("cls");
    cout << "====== Welcome to Lognuts ======" << endl
         << "Pilih Menu: " << endl << endl
         << "1. Service" << endl
         << "2. Semua Data Pelanggan" << endl
         << "3. Data Pelanggan" << endl
         << "4. Keluar" << endl << endl
         << "Pilihan: ";

    cin >> pil;

    if (pil == 1)
    {
        serviceMenu();
    }
    else if (pil == 2)
    {
        allCust();
    }
    else if (pil == 3)
    {
        singleCust();
    }
    else if (pil == 4)
    {
        cout << endl << "====== Thank you for using Lognuts! ======";
        tutup = 1;
    }
    
}

int main()
{
    ifstream fileCust("Customer.txt");
    string namaCust;

    while (getline(fileCust, namaCust)) 
    {
        Customer *custBaru = new Customer();
        custBaru -> nama = namaCust;
        
        getline(fileCust, custBaru -> telepon);
        getline(fileCust, custBaru -> alamat);
        getline(fileCust, custBaru -> umur);
        getline(fileCust, custBaru -> gender);

        custBaru -> headServ = NULL;
        custBaru -> next = NULL;
        custBaru -> prev = NULL;
        
        if (headCust == NULL)
        {
            headCust = tailCust = custBaru;
        }
        else
        {
            tailCust -> next = custBaru;
            custBaru -> prev = tailCust;
            tailCust = custBaru;
        }
    }
    fileCust.close();

    ifstream fileServ("Service.txt");
    string namaCustServ;

    while (getline(fileServ, namaCustServ)) 
    {
        Service *servBaru = new Service();
        getline(fileServ, servBaru -> tipeMobil);
        getline(fileServ, servBaru -> merekMobil);
        getline(fileServ, servBaru -> kendala);
        getline(fileServ, servBaru -> namaMontir);

        servBaru -> allnext = NULL;
        servBaru -> next = NULL;
        servBaru -> prev = NULL;

        Customer* that = headCust;
        while(that != NULL)
        {
            if (that -> nama == namaCustServ)
                break;
            that = that -> next;
        }

        if (that != NULL)
        {
            servBaru -> next = that -> headServ;
            that -> headServ = servBaru;
            servBaru -> dataCust = that;
        }
        
        servBaru  ->  allnext = servHistory;
        servHistory = servBaru;
    }
    fileServ.close();

    while (tutup != 1)
    {
        Menu();
    }
    
    return 0;
}