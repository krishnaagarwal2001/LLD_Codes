#include<bits/stdc++.h>
using namespace std;

class JSONAnalyticsTool{
    string pJsonData;

    public:
        void setJsonData(string jsonData){
            pJsonData = jsonData;
        }

        void AnalyzeData(){
            if (pJsonData.find("json") != string::npos) {
                cout << "Analysing JSON Data - " << pJsonData << endl;
            } else {
                cout << "Not correct format. Can't analyse! " << endl;
            }    
        }
};

class AnalyticsTool {
    public:
        virtual void AnalyzeData()=0;
        virtual ~AnalyticsTool(){}
};

class XMLToJSONAdapter: public AnalyticsTool, public JSONAnalyticsTool{
    public:
        XMLToJSONAdapter(string xmlData){
            cout<<"Converting the XML Data '" << xmlData <<"' to JSON Data!"<<endl;
            string newData = xmlData + " in json";
            setJsonData(newData);
        }

        void AnalyzeData()
        {    
            //Could convert here instead of the constructor
            JSONAnalyticsTool::AnalyzeData();
        }
};

int main(){
    string xmlData = "Sample Data";
    JSONAnalyticsTool tool1;
    tool1.setJsonData(xmlData);
    tool1.AnalyzeData();

    cout<<"----------------------------------------------"<<endl;

    AnalyticsTool *tool2 = new XMLToJSONAdapter(xmlData);
    tool2->AnalyzeData();
    delete tool2;
    return 0;
}