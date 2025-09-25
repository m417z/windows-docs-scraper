# WS_CAPI_ASYMMETRIC_SECURITY_KEY_HANDLE structure

## Description

The type for specifying asymmetric cryptographic keys as CAPI 1.0 key
handles.

When this structure is used in an API (such as
with [XML token creation](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatexmlsecuritytoken) and subsequent
[use of that XML
token](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_token_message_security_binding) for a channel), the application is responsible for making
sure that the HCRYPTPROV remains valid as long as the key is in
use. The application is also responsible for freeing the handle when
it is no longer in use.

This type is supported only on pre-Windows Vista platforms: for
Windows Vista and later, please use [WS_NCRYPT_ASYMMETRIC_SECURITY_KEY_HANDLE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_ncrypt_asymmetric_security_key_handle).

## Members

### `keyHandle`

The base type from which this type and all other key handle types derive.

### `provider`

The cryptographic provider.

### `keySpec`

The key specification.