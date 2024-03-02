#include <iostream>
#include <cmath>
using namespace std;

const double phi = 3.14;
const double radius = 6371;

//====START NO 1 ====
typedef struct{
    int degres;
    int minutes;
    char direction;
}long_lat_t;
//====END NO 1 ====


//====START NO 2 ====
typedef struct{
    char placa[20];
    long_lat_t longitude;
    long_lat_t latitude;
}location_t;
//====END NO 2 ====


double konversi(double degrees){
    return degrees*phi/180;
}

double jarak(location_t loc_1, location_t loc_2){
    double long1 = konversi(loc_1.longitude.degres + (loc_1.longitude.minutes/60));
    double lat1 = konversi(loc_1.latitude.degres + (loc_1.latitude.minutes/60));

    double long2 = konversi(loc_2.longitude.degres + (loc_2.longitude.minutes/60));
    double lat2 = konversi((loc_2.latitude.degres) + (loc_2.latitude.minutes/60));

    double dlong = long2 - long1;
    double dlat = lat2 - lat1;

    double ans = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2),2);
    double a = 2 * atan2(sqrt(ans), sqrt(1 - ans));

    return radius*a;
}

int main()
{
    location_t hotel[3] = {
        {"Hotel Beleza", {12, 23, 'N'}, {4, 36, 'E'}},
        {"Hotel Swizbel", {13, 45, 'S'}, {5, 30, 'N'}},
        {"Hotel Mariana", {14, 10, 'S'}, {6, 15, 'E'}}
    };

    for (int i = 0; i < 3; i++) {
        cout << "Nama Hotel: " << hotel[i].placa << endl;
        cout << "Longitude: " << hotel[i].longitude.degres << ": " << hotel[i].longitude.minutes << "' " << hotel[i].longitude.direction << endl;
        cout << "Latitude: " << hotel[i].latitude.degres << ": " << hotel[i].latitude.minutes << "' " << hotel[i].latitude.direction << endl;
    }

    double hitung_jarak = jarak(hotel[0], hotel[1]);
    cout << "\nJarak antara " << hotel[0].placa << " dan " << hotel[1].placa << " adalah: " << hitung_jarak << " km" << endl;

    return 0;
}


