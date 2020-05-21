# IIJIoTClient
Spresense+LTE拡張ボード Arduino IDE用  
IIJ IoT サービス用のクライアントライブラリです。

# version
version 0.1

# ライセンス  
License MIT

# 使い方
* このライブラリを Arduino IDE にインクルードしてください。
* Arduino IDE からスケッチ例を参照してください。

# 注意事項

* このライブラリは *IIJ非公式* です。このライブラリに関する問い合わせはIIJに行わないでください。

# 事前に作業しておくこと

* ライブラリマネージャより "ArduinoHttpClient" をインストールしておく必要があります。

# IIJIoTClient ライブラリ説明

## コンストラクタ

* IIJIoTClient()  
  コンストラクタ。

## public関数

* int sendByHttp(const String &json)  
  IIJ IoTサービスにJSON文字列のデータをHTTPで送信します。
  * 引数
    * json: POSTするJSON文字列
  * 戻り値
    * POSTした結果のhttpステータスコード

* int sendByHttp(const String &nspace, const String &name, const float value)  
  IIJ IoTサービスにデータをHTTPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
  * 戻り値
    * POSTした結果のhttpステータスコード

* int sendByHttp(const String &nspace, const String &name, const float value, const String &tagName, const String &tagValue, const long timestamp = -1L)  
  IIJ IoTサービスにデータをHTTPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
    * tagName: Tag の名称
    * tagValue: Tag の値
    * timestamp: timestamp (unixtime値)
  * 戻り値
    * POSTした結果のhttpステータスコード

* int sendByHttp(const char *nspace, const char *name, const float value, const char *tagName = "", const char *tagValue = "", const long timestamp = -1L)  
  IIJ IoTサービスにデータをHTTPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
    * tagName: Tag の名称
    * tagValue: Tag の値
    * timestamp: timestamp (unixtime値)
  * 戻り値
    * POSTした結果のhttpステータスコード

* boolean sendByUdp(const String &json)  
  IIJ IoTサービスにJSON文字列のデータをUDPで送信します。
  * 引数
    * json: 送信するJSON文字列
  * 戻り値
    * true:送信成功  false:失敗

* boolean sendByUdp(const String &nspace, const String &name, const float value)  
  IIJ IoTサービスにデータをUDPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
  * 戻り値
    * true:送信成功  false:失敗

* boolean sendByUdp(const String &nspace, const String &name, const float value, const String &tagName, const String &tagValue, const long timestamp = -1L)  
  IIJ IoTサービスにデータをUDPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
    * tagName: Tag の名称
    * tagValue: Tag の値
    * timestamp: timestamp (unixtime値)
  * 戻り値
    * true:送信成功  false:失敗

* boolean sendByUdp(const char *nspace, const char *name, const float value, const char *tagName = "", const char *tagValue = "", const long timestamp = -1L)  
  IIJ IoTサービスにデータをUDPで送信します。
  * 引数
    * nspace: namespace の文字列
    * name: name の文字列
    * value: 値
    * tagName: Tag の名称
    * tagValue: Tag の値
    * timestamp: timestamp (unixtime値)
  * 戻り値
    * true:送信成功  false:失敗

* void setDebugSerial(Stream &debug)  
  引数にSerialオブジェクトを渡すと、そのSerialにデバッグ用の出力を行うようになります。  

# リンク
* IIJ IoT サービス
  https://www.iij.ad.jp/biz/iot/


# history
* ver. 0.1: 初回公開

## 今後の開発予定
* ファイルを送信する機能を追加する
* デバイスのステータスを取得する機能を追加する
* UDPパケット受信機能を追加する


