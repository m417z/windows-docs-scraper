# WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL structure

## Description

Type for supplying a Windows Integrated Authentication credential based on the current Windows identity. If this credential subtype is used for a security binding, the current thread token on the thread that calls [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) or [WsOpenServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenserviceproxy) is used as the Windows identity when sending messages or making service calls.

[WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel) and [WsOpenServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenservicehost) do not support this credential type when called from an impersonating thread.

This type derives from the base type [WS_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_windows_integrated_auth_credential). For an instance of this type, the type selector field **credential.credentialType** must have the value **WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL_TYPE**.

## Members

### `credential`

The base type from which this type and all other Windows Integrated Authentication credential types derive.
See [WS_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_windows_integrated_auth_credential).