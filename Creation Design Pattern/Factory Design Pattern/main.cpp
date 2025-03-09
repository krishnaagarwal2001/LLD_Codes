#include<bits/stdc++.h>
using namespace std;

enum class LogLevel {
    DEBUG,
    INFO,
    ERROR,
};

class ILogger {
    public:
        virtual void log(const string& msg)=0;
        virtual ~ILogger() {}
};

class InfoLogger: public ILogger {
    public:
        void log(const string& msg){
            cout<<"INFO: "<<msg<<endl;
        }
};

class DebugLogger: public ILogger {
    public:
        void log(const string& msg){
            cout<<"DEBUG: "<<msg<<endl;
        }
};

class ErrorLogger: public ILogger {
    public:
        void log(const string& msg){
            cout<<"ERROR: "<<msg<<endl;
        }
};

class ILoggerFactory {
    public:
        virtual ILogger* createLogger()=0;
};

class InfoLoggerFactory: public ILoggerFactory{
    public:
        ILogger* createLogger(){
            return new InfoLogger();
        }
};

class DebugLoggerFactory: public ILoggerFactory{
    public:
        ILogger* createLogger(){
            return new DebugLogger();
        }
};


class ErrorLoggerFactory: public ILoggerFactory{
    public:
        ILogger* createLogger(){
            return new ErrorLogger();
        }
};

int main(){
    ILoggerFactory* infoLoggerFactory = new InfoLoggerFactory;
    ILogger* infoLogger = infoLoggerFactory->createLogger();

    ILoggerFactory* debugLoggerFactory = new DebugLoggerFactory;
    ILogger* debugLogger = debugLoggerFactory->createLogger();

    ILoggerFactory* errorLoggerFactory = new ErrorLoggerFactory;
    ILogger* errorLogger = errorLoggerFactory->createLogger();

    debugLogger -> log("Debug msg");
    errorLogger -> log("Error msg");
    infoLogger -> log("Info msg");

    delete debugLogger;
    delete errorLogger;
    delete infoLogger;

    return 0;

}