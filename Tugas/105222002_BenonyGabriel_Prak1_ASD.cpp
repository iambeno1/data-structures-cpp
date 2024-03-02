#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.14;


typedef struct
{
    int degrees;
    int minutes;
    char direction;

}long_lat_t;

typedef struct
{
    char place[20];
    long_lat_t longitude, latitude;

}location_t;

void jarak()
{
    location_t Lokasi_Hotel[2];
    int dlong, dlat;
    if (Lokasi_Hotel[0].longitude.degrees > Lokasi_Hotel[1].longitude.degrees)
    {
        dlong = Lokasi_Hotel[0].longitude.degrees - Lokasi_Hotel[1].longitude.degrees;
        dlat = Lokasi_Hotel[0].latitude.degrees - Lokasi_Hotel[1].latitude.degrees;
    }
    else
    {
        dlong = Lokasi_Hotel[1].longitude.degrees - Lokasi_Hotel[0].longitude.degrees;
        dlat = Lokasi_Hotel[1].latitude.degrees - Lokasi_Hotel[0].latitude.degrees;
    }
    float ans = pow(sin(dlat / 2), 2) + cos(Lokasi_Hotel[1].latitude.degrees) * cos(Lokasi_Hotel[0].latitude.degrees)
    * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));
    int R = 6371;
    ans = ans * R;

    cout << "jarak: " << ans;


}

void convert()
{
    location_t Lokasi_Hotel[2];
    float radius;
    radius = Lokasi_Hotel[0].longitude.degrees * pi / 180;
    cout << "conversion: " << radius;
    radius = Lokasi_Hotel[1].longitude.degrees * pi / 180;
    cout << "conversion: " << radius;


}

int main()
{
    location_t Lokasi_Hotel[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Nama Hotel: ";
        for (int j = 0; j < 20; j++)
        {
            cin >> Lokasi_Hotel[i].place[j];
        }
        cout << endl;
        cout << "Longitude degrees: ";
        cin >> Lokasi_Hotel[i].longitude.degrees;
        cout << "Longitude minutes: ";
        cin >> Lokasi_Hotel[i].longitude.minutes;
        cout << "Longitude direction: ";
        cin >> Lokasi_Hotel[i].longitude.direction;
        cout << endl;

        cout << "latitude degrees: ";
        cin >> Lokasi_Hotel[i].latitude.degrees;
        cout << "latitude minutes: ";
        cin >> Lokasi_Hotel[i].latitude.minutes;
        cout << "latitude direction: ";
        cin >> Lokasi_Hotel[i].latitude.direction;

    }

    jarak();
    convert();

    return 0;
}
