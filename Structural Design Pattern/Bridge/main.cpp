#include<bits/stdc++.h>
using namespace std;

class NavigationImpl{
    public:
        virtual void navigateTo(string destination)=0;
};

class GoogleMaps: public NavigationImpl{
    public:
        void navigateTo(string destination){
            cout<<"Google Maps"<<endl;
        }
};

class AppleMaps: public NavigationImpl{
    public:
        void navigateTo(string destination){
            cout<<"Apple Maps"<<endl;
        }
};

class NavigationSystem{
    protected:
        NavigationImpl* navigationImpl;
    
    public:
        virtual void navigate(string destination)=0;
};

class UberRide: public NavigationSystem{
    private:
        string driverName;

    public:
        UberRide(string driverName) : driverName(driverName) {}

        void navigate(string destination)
        {
            cout << "Uber ride with " << driverName << " to " << destination << " using ";
            navigationImpl->navigateTo(destination);
        }
    
        void setNavigationImpl(NavigationImpl *impl)
        {
            navigationImpl = impl;
        }
};

class UberEats: public NavigationSystem{
    private:
        string restaurantName;

    public:
        UberEats(string restaurantName) : restaurantName(restaurantName) {}

        void navigate(string destination)
        {
            cout << "Uber Eats delivery from " << restaurantName << " to " << destination << " using ";
            navigationImpl->navigateTo(destination);
        }
    
        void setNavigationImpl(NavigationImpl *impl)
        {
            navigationImpl = impl;
        }
};

int main(){
    UberRide uber("Keerti");

    UberEats uberEats("Pizza Palace");

    GoogleMaps googleMaps;
    AppleMaps appleMaps;

    uber.setNavigationImpl(&googleMaps);
    uberEats.setNavigationImpl(&appleMaps);

    uber.navigate("Central Park");
    uberEats.navigate("123 HSR");

    return 0;
}