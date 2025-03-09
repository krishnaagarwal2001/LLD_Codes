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

class LoggerFactory {
    public:
        static ILogger* createLogger(LogLevel pLogLevel){
            if(pLogLevel == LogLevel::DEBUG)
                return new DebugLogger();

            if(pLogLevel == LogLevel::INFO)
                return new InfoLogger();

            if(pLogLevel == LogLevel::ERROR)
                return new ErrorLogger();

            return nullptr;
        }
};

int main(){
    ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::DEBUG);
    ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);
    ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);

    debugLogger -> log("Debug msg");
    errorLogger -> log("Error msg");
    infoLogger -> log("Info msg");

    delete debugLogger;
    delete errorLogger;
    delete infoLogger;

    return 0;
}