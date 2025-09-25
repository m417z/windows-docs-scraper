# EncodingType enumeration

## Description

The **EncodingType** enumeration specifies the type of encoding applied to a byte array for display purposes.

## Constants

### `XCN_CRYPT_STRING_BASE64HEADER:0`

The string is base64 encoded with beginning and ending certificate headers. Base64 is an encoding scheme used to transmit binary data. The data to be encoded is examined three bytes at a time. Every six bits in the 24-bit buffer is used as an index into a text string. The strings used vary depending on the type of data being encoded. The following string is commonly used for Multipurpose Internet Mail Extensions (MIME) email base64 encoding.

``` syntax
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/
```

 The following example shows a certificate that is base64 encoded and includes the beginning and ending headers.

``` syntax
-----BEGIN CERTIFICATE-----
MIIBqDCCARECAQAwaTELMAkGA1UEBhMCVVMxDjAMBgNVBAgTBVRleGFzMRMwEQYD
VQQHEwpMYXNDb2xpbmFzMRIwEAYDVQQKEwlNaWNyb3NvZnQxDjAMBgNVBAsTBUl0
ZWFtMREwDwYDVQQDFAhOVFZPT0RPTzCBnjANBgkqhkiG9w0BAQEFAAOBjAAwgYgC
gYBxmmAWKbLJHg5TuVyjgzWW0JsY5Shaqd7BDWtqhzy4HfRTW22f31rlm8NeSXHn
EhLiwsGgNzWHJ8no1QIYzAgpDR79oqxvgrY4WS3PXT7OLwIDAQABoAAwDQYJKoZI
hvcNAQEEBQADgYEAVcyI4jtnnV6kMiByiq4Xg99yL0U7bIpEwAf3MIZHS7wuNqfY
acfhbRj6VFHT8ObprKGPmqXJvwrBmPrEuCs4Ik6PidAAeEfoaa3naIbM73tTvKN+
WD30lAfGBr8SZixLep4pMIN/wO0eu6f30cBuoPtDnDulNT8AuQHjkJIc8Qc=
-----END CERTIFICATE-----
```

### `XCN_CRYPT_STRING_BASE64:0x1`

The string is base64 encoded without beginning and ending certificate headers.

### `XCN_CRYPT_STRING_BINARY:0x2`

The string is a pure binary sequence. It is not encoded.

### `XCN_CRYPT_STRING_BASE64REQUESTHEADER:0x3`

The string is base64 encoded with beginning and ending certificate request headers. This is shown in the following example.

``` syntax
-----BEGIN NEW CERTIFICATE REQUEST-----
MIIDBjCCAm8CAQAwcTERMA8GA1UEAxMIcXV1eC5jb20xDzANBgNVBAsTBkJyYWlu
czEWMBQGA1UEChMNRGV2ZWxvcE1lbnRvcjERMA8GA1UEBxMIVG9ycmFuY2UxEzAR
BgNVBAgTCkNhbGlmb3JuaWExCzAJBgNVBAYTAlVTMIGfMA0GCSqGSIb3DQEBAQUA
A4GNADCBiQKBgQDFUxFtzr170yxptKuGI1590Sta5z2dVElLfjAn+q4T1uZE3DiH
HXNRHW1eS9W2aeMZhRnYRi5U8eOdG3RUO4YXy4B1sqfy5I0qjjySA89ghVd/6JcA
K1nhGJL9FPJ6XKVUNLez7NpSCFlYs5foyTqyxDkHzTnQwRwkkwQ9dlbnfwIDAQAB
oIIBUzAaBgorBgEEAYI3DQIDMQwWCjUuMC4yMTk1LjIwNQYKKwYBBAGCNwIBDjEn
MCUwDgYDVR0PAQH/BAQDAgTwMBMGA1UdJQQMMAoGCCsGAQUFBwMBMIH9BgorBgEE
AYI3DQICMYHuMIHrAgEBHloATQBpAGMAcgBvAHMAbwBmAHQAIABSAFMAQQAgAFMA
QwBoAGEAbgBuAGUAbAAgAEMAcgB5AHAAdABvAGcAcgBhAHAAaABpAGMAIABQAHIA
bwB2AGkAZABlAHIDgYkAXxNuAz6gcBaZUdef8WQ2PAroKMW8sprcKv7QD2encz6/
Wct9DZ5CkGynLGy0f+Lff7ViSDJqxYWaJ68ddqgXyAqIilF63kivPTiC6yxLaNX6
5v3cnKFx4UrUrGXZtub7M7/NuxSipOW0Vv7yCHganypxDyRzp6IhulEnL4APEH4A
AAAAAAAAADANBgkqhkiG9w0BAQUFAAOBgQBljJb1ZhWOwOLfzfHbC3yxGkXDy9w3
NA7uhQOvgntnqmSmdHP9nsM3DnxwaHb3EVxMKbAuLsSRDAE1KGqeamvQ3uFjuuL0
5q4nKhX25LyGFDSc6h1OHcv+0ugZ/9klsiViSeEGpMwllUf057o7q1Vls4HN22vM
wkcejcttDjo3Kw==
-----END NEW CERTIFICATE REQUEST-----
```

### `XCN_CRYPT_STRING_HEX:0x4`

The string is hexadecimal encoded. Each 4-bit nibble of the string is represented as a number between zero and nine or a letter between A and F (or a and f). This is shown in the following example.

``` syntax
3a 20 63 65 72 74 6c 69  62 5c 6c 64 61 70 2e 63
70 70 28 32 31 33 31 29  3a 20 6c 64 61 70 65 72
...
```

### `XCN_CRYPT_STRING_HEXASCII:0x5`

The string is hexadecimal encoded, and the corresponding ASCII characters are displayed. This is shown in the following example.

``` syntax
3a 20 63 65 72 74 6c 69  62 5c 6c 64 61 70 2e 63   : certlib\ldap.c
70 70 28 32 31 33 31 29  3a 20 6c 64 61 70 65 72   pp(2131): ldaper
...
```

### `XCN_CRYPT_STRING_BASE64_ANY:0x6`

The string is base64 encoded. Enumeration values are tried in the following order:

1. **XCN_CRYPT_STRING_BASE64HEADER**
2. **XCN_CRYPT_STRING_BASE64**

### `XCN_CRYPT_STRING_ANY:0x7`

Enumeration values are tried in the following order:

1. **XCN_CRYPT_STRING_BASE64_ANY**
2. **XCN_CRYPT_STRING_BINARY**

The **XCN_CRYPT_STRING_BINARY** value always succeeds.

### `XCN_CRYPT_STRING_HEX_ANY:0x8`

Enumeration values are tried in the following order:

1. **XCN_CRYPT_STRING_HEXADDR**
2. **XCN_CRYPT_STRING_HEXASCIIADDR**
3. **XCN_CRYPT_STRING_HEXASCII**
4. **XCN_CRYPT_STRING_HEX**

### `XCN_CRYPT_STRING_BASE64X509CRLHEADER:0x9`

The string is base64 encoded with beginning and ending [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) headers. This is shown in the following example.

``` syntax
-----BEGIN X509 CRL-----
MIIDBjCCAm8CAQAwcTERMA8GA1UEAxMIcXV1eC5jb20xDzANBgNVBAsTBkJyYWlu
czEWMBQGA1UEChMNRGV2ZWxvcE1lbnRvcjERMA8GA1UEBxMIVG9ycmFuY2UxEzAR
BgNVBAgTCkNhbGlmb3JuaWExCzAJBgNVBAYTAlVTMIGfMA0GCSqGSIb3DQEBAQUA
A4GNADCBiQKBgQDFUxFtzr170yxptKuGI1590Sta5z2dVElLfjAn+q4T1uZE3DiH
HXNRHW1eS9W2aeMZhRnYRi5U8eOdG3RUO4YXy4B1sqfy5I0qjjySA89ghVd/6JcA
K1nhGJL9FPJ6XKVUNLez7NpSCFlYs5foyTqyxDkHzTnQwRwkkwQ9dlbnfwIDAQAB
oIIBUzAaBgorBgEEAYI3DQIDMQwWCjUuMC4yMTk1LjIwNQYKKwYBBAGCNwIBDjEn
MCUwDgYDVR0PAQH/BAQDAgTwMBMGA1UdJQQMMAoGCCsGAQUFBwMBMIH9BgorBgEE
AYI3DQICMYHuMIHrAgEBHloATQBpAGMAcgBvAHMAbwBmAHQAIABSAFMAQQAgAFMA
QwBoAGEAbgBuAGUAbAAgAEMAcgB5AHAAdABvAGcAcgBhAHAAaABpAGMAIABQAHIA
bwB2AGkAZABlAHIDgYkAXxNuAz6gcBaZUdef8WQ2PAroKMW8sprcKv7QD2encz6/
Wct9DZ5CkGynLGy0f+Lff7ViSDJqxYWaJ68ddqgXyAqIilF63kivPTiC6yxLaNX6
5v3cnKFx4UrUrGXZtub7M7/NuxSipOW0Vv7yCHganypxDyRzp6IhulEnL4APEH4A
AAAAAAAAADANBgkqhkiG9w0BAQUFAAOBgQBljJb1ZhWOwOLfzfHbC3yxGkXDy9w3
NA7uhQOvgntnqmSmdHP9nsM3DnxwaHb3EVxMKbAuLsSRDAE1KGqeamvQ3uFjuuL0
5q4nKhX25LyGFDSc6h1OHcv+0ugZ/9klsiViSeEGpMwllUf057o7q1Vls4HN22vM
wkcejcttDjo3Kw==
-----END X509 CRL-----
```

### `XCN_CRYPT_STRING_HEXADDR:0xa`

The string is hexadecimal encoded and displayed as a hexadecimal address. This is shown in the following example.

``` syntax
0000  3a 20 63 65 72 74 6c 69  62 5c 6c 64 61 70 2e 63
0010  70 70 28 32 31 33 31 29  3a 20 6c 64 61 70 65 72
...
```

### `XCN_CRYPT_STRING_HEXASCIIADDR:0xb`

The string is hexadecimal encoded and displayed as a hexadecimal address along with the corresponding ASCII characters. This is shown in the following example.

``` syntax
0000  3a 20 63 65 72 74 6c 69  62 5c 6c 64 61 70 2e 63   : certlib\ldap.c
0010  70 70 28 32 31 33 31 29  3a 20 6c 64 61 70 65 72   pp(2131): ldaper
...
```

### `XCN_CRYPT_STRING_HEXRAW:0xc`

The string is hexadecimal encoded and displayed without punctuation. **XCN_CRYPT_STRING_HEXRAW** is available only with Windows Vista.

``` syntax
3a20636572746c69625c6c6461702e6370702832313331293a206c6461706572...
```

### `XCN_CRYPT_STRING_BASE64URI:0xd`

### `XCN_CRYPT_STRING_ENCODEMASK:0xff`

### `XCN_CRYPT_STRING_CHAIN:0x100`

### `XCN_CRYPT_STRING_TEXT:0x200`

### `XCN_CRYPT_STRING_PERCENTESCAPE:0x8000000`

### `XCN_CRYPT_STRING_HASHDATA:0x10000000`

### `XCN_CRYPT_STRING_STRICT:0x20000000`

### `XCN_CRYPT_STRING_NOCRLF:0x40000000`

Removes carriage return and line feed control characters from the encoded string.

### `XCN_CRYPT_STRING_NOCR:0x80000000`

Removes the carriage return control character from the encoded string.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)