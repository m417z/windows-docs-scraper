# WS_NCRYPT_ASYMMETRIC_SECURITY_KEY_HANDLE structure

## Description

The type for specifying asymmetric cryptographic keys as a CryptoNG
NCRYPT_KEY_HANDLE.

When this structure is used in an API (such as with
[XML token creation](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatexmlsecuritytoken)) and subsequent
[use of that XML
token](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_token_message_security_binding) for a channel), the application is responsible for making
sure that the NCRYPT_KEY_HANDLE remains valid as long as the key is in
use. The application is also responsible for freeing the handle when
it is no longer in use.

This type is supported only on Windows Vista and later platforms.

## Members

### `keyHandle`

The base type from which this type and all other key handle types derive.

### `asymmetricKey`

The CryptoNG asymmetric cryptographic key.