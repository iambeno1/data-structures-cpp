#include <iostream>
#include <cmath>
using namespace std;

typedef struct
{
    int degrees;
    int minutes;
    char direction;
}long_lat_t;

typedef struct location_s
{
    string place;
    long_lat_t longitude, latitude;
    struct location_s *linkp;
}location_t;

location_t *Lokasi_Hotel, *prevp, *newp;

void user_input()
{
    Lokasi_Hotel = new location_t;
    prevp = Lokasi_Hotel;
    while (true)
    {
        newp = new location_t;
        cout << "\nNama Hotel: ";
        cin >> (*newp).place;
        if ((*newp).place == "stop")
        {
            break;
        }
        cout << "Longitude degrees: ";
        cin >> (*newp).longitude.degrees;
        cout << "Longitude minutes: ";
        cin >> (*newp).longitude.minutes;
        cout << "Longitude direction: ";
        cin >> (*newp).longitude.direction;
        cout << endl;

        cout << "latitude degrees: ";
        cin >> (*newp).latitude.degrees;
        cout << "latitude minutes: ";
        cin >> (*newp).latitude.minutes;
        cout << "latitude direction: ";
        cin >> (*newp).latitude.direction;
        (*prevp).linkp = newp;
        prevp = newp;

    }
    prevp->linkp = nullptr;
}

void show_all(location_t *headp)
{
    while (headp != nullptr)
    {
        headp = (*headp).linkp;
        if (headp != nullptr)
        {
            cout << "Place: " << (*headp).place << endl;
            cout << "Longitude degrees: " << (*headp).longitude.degrees << endl;
            cout << "Longitude minutes: " << (*headp).longitude.minutes << endl;
            cout << "Longitude direction: " << (*headp).longitude.direction << endl;
            cout << "Latitude degrees: " << (*headp).latitude.degrees << endl;
            cout << "Latitude minutes: " << (*headp).latitude.minutes << endl;
            cout << "Latitude direction: " << (*headp).latitude.direction << endl;
        }
    }
}

int main()
{
    user_input();
    show_all(Lokasi_Hotel);

    return 0;
}