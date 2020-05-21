/*
    IIJIoTClient.cpp - IIJ IoT Service Client for SpresenseLTE
    development by nara256  https://github.com/nara256/
    version 0.1

    License MIT
*/

#include "IIJIoTClient.h"

#define HEADER_CONTENT_TYPE         "Content-Type"
#define HEADER_CONTENT_TYPE_VALUE   "application/json;charset=UTF-8"
#define HEADER_CONTENT_LENGTH       "Content-Length"

#define DEFAULT_IOT_HOST      "gw.iot.iij.jp"
#define DEFAULT_IOT_HTTP_PORT 80
#define DEFAULT_IOT_PATH      "/v1"
#define DEFAULT_IOT_UDP_PORT  19920

static String esc(const String &src)
{
    String dest(src);
    dest.replace("\\", "\\\\");
    dest.replace("\"", "\\\"");
    return dest;
}

IIJIoTClient::IIJIoTClient()
{
}

IIJIoTClient::~IIJIoTClient()
{
}

void IIJIoTClient::debug(const String &val)
{
    if (m_debug != NULL)
    {
        m_debug->println(val);
        yield();
    }
}

void IIJIoTClient::debug(const char *val)
{
    String s(val);
    debug(s);
}


void IIJIoTClient::setDebugSerial(Stream &debug)
{
    m_debug = &debug;
}

String IIJIoTClient::createJson(
    const String &nspace, const String &name, float value,
    const String &tagName, const String &tagValue, const long timestamp)
{
    String json;
    json += "{";
    json += "\"namespace\":\"" + esc(nspace) + "\",";
    json += "\"name\":\"" + esc(name) + "\",";
    if (!tagName.equals(""))
        json += "\"tags\":{\"" + esc(tagName) + "\":\"" + esc(tagValue) + "\"},";
    if (timestamp >= 0)
        json += "\"timestamp\":" + String(timestamp) + ",";
    json += "\"value\":" + String(value);
    json += "}";
    return json;
}

int IIJIoTClient::sendByHttp(
    const String &nspace, const String &name, const float value)
{
    String na("");
    return sendByHttp(nspace, name, value, na, na);
}

int IIJIoTClient::sendByHttp(
    const char *nspace, const char *name, const float value,
    const char *tagName, const char *tagValue, const long timestamp)
{
    String ns(nspace), n(name), tn(tagName), tv(tagValue);
    return sendByHttp(ns, n, value, tn, tv, timestamp);
}

int IIJIoTClient::sendByHttp(
    const String &nspace, const String &name, const float value,
    const String &tagName, const String &tagValue, const long timestamp)
{
    String json = createJson(nspace, name, value, tagName, tagValue, timestamp);
    return sendByHttp(json);
}

int IIJIoTClient::sendByHttp(const String &json)
{
    int status = -1;

    LTEClient lteClient;
    HttpClient client = HttpClient(lteClient, DEFAULT_IOT_HOST, DEFAULT_IOT_HTTP_PORT);
    client.beginRequest();
    client.post(DEFAULT_IOT_PATH);
    client.sendHeader(HEADER_CONTENT_TYPE, HEADER_CONTENT_TYPE_VALUE);
    client.sendHeader(HEADER_CONTENT_LENGTH, json.length());
    client.beginBody();
    debug("POST " + json);
    client.print(json);
    client.endRequest();
    status = client.responseStatusCode();
    debug("status=" + String(status));

    return status;
}


boolean IIJIoTClient::sendByUdp(
    const String &nspace, const String &name, const float value)
{
    String na("");
    return sendByUdp(nspace, name, value, na, na);
}

boolean IIJIoTClient::sendByUdp(
    const char *nspace, const char *name, const float value,
    const char *tagName, const char *tagValue, const long timestamp)
{
    String ns(nspace), n(name), tn(tagName), tv(tagValue);
    return sendByUdp(ns, n, value, tn, tv, timestamp);
}

boolean IIJIoTClient::sendByUdp(
    const String &nspace, const String &name, const float value,
    const String &tagName, const String &tagValue, const long timestamp)
{
    String json = createJson(nspace, name, value, tagName, tagValue, timestamp);
    return sendByUdp(json);
}

boolean IIJIoTClient::sendByUdp(const String &json)
{
    boolean status = false;

    LTEUDP udp;
    if (udp.beginPacket(DEFAULT_IOT_HOST, DEFAULT_IOT_UDP_PORT))
    {
        debug("UDP write " + json);
        char* cjson = json.c_str();
        udp.write(cjson, strlen(cjson));
        if(udp.endPacket()) status = true;
    }
    debug("status=" + String(status?"true":"false"));
    return status;
}

void IIJIoTClient::debugJson(const String &nspace, const String &name, float value,
                                   const String &tagName, const String &tagValue, const long timestamp)
{
    String json = createJson(nspace, name, value, tagName, tagValue, timestamp);
    debug(json);
}
