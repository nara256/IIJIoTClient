/*
    IIJIoTClient.h - IIJ IoT Service Client for SpresenseLTE
    development by nara256  https://github.com/nara256/
    version 0.1

    License MIT
*/
#ifndef IIJIoTClient_h_
#define IIJIoTClient_h_

#include "Arduino.h"
#include <LTEUDP.h>
#include <LTEClient.h>
#include <ArduinoHttpClient.h>

class IIJIoTClient
{
private:
    Stream *m_debug = NULL;

    void debug(const String &val);
    void debug(const char *val);

    String createJson(
        const String &nspace, const String &name, float value,
        const String &tagName, const String &tagValue, const long timestamp);

public:
    IIJIoTClient();
    virtual ~IIJIoTClient();
    void setDebugSerial(Stream &debug);

    void debugJson(const String &nspace, const String &name, const float value,
                   const String &tagName, const String &tagValue, const long timestamp);

    boolean sendByUdp(const String &json);
    boolean sendByUdp(const String &nspace, const String &name, const float value);
    boolean sendByUdp(const String &nspace, const String &name, const float value,
             const String &tagName, const String &tagValue, const long timestamp = -1L);
    boolean sendByUdp(const char *nspace, const char *name, const float value,
             const char *tagName = "", const char *tagValue = "", const long timestamp = -1L);

    int sendByHttp(const String &json);
    int sendByHttp(const String &nspace, const String &name, const float value);
    int sendByHttp(const String &nspace, const String &name, const float value,
             const String &tagName, const String &tagValue, const long timestamp = -1L);
    int sendByHttp(const char *nspace, const char *name, const float value,
             const char *tagName = "", const char *tagValue = "", const long timestamp = -1L);

};

#endif // IIJIoTClient_h_
