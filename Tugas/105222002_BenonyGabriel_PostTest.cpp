#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct
{
    int degrees;
    int minutes;
    char direction;

} long_lat_t;

typedef struct location_s
{
    string place;
    long_lat_t longitude, latitude;
} location_t;

int main()
{
    vector<location_t> location;

    while (true)
    {
        location_t newp;
        cout << "Nama Hotel: ";
        cin >> newp.place;
        if (newp.place == "stop")
        {
            break;
        }
        cout << "Longitude degrees: ";
        cin >> newp.longitude.degrees;
        cout << "Longitude minutes: ";
        cin >> newp.longitude.minutes;
        cout << "Longitude direction: ";
        cin >> newp.longitude.direction;
        cout << endl;

        cout << "Latitude degrees: ";
        cin >> newp.latitude.degrees;
        cout << "Latitude minutes: ";
        cin >> newp.latitude.minutes;
        cout << "Latitude direction: ";
        cin >> newp.latitude.direction;

        location.push_back(newp);
    }

    for (const location_t &hotel : location)
    {
        cout << "Place: " << hotel.place << endl;
        cout << "Longitude degrees: " << hotel.longitude.degrees << endl;
        cout << "Longitude minutes: " << hotel.longitude.minutes << endl;
        cout << "Longitude direction: " << hotel.longitude.direction << endl;
        cout << "Latitude degrees: " << hotel.latitude.degrees << endl;
        cout << "Latitude minutes: " << hotel.latitude.minutes << endl;
        cout << "Latitude direction: " << hotel.latitude.direction << endl;
    }

    return 0;
}