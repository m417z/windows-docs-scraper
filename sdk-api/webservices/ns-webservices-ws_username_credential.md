# WS_USERNAME_CREDENTIAL structure

## Description

The abstract base type for all username/password credentials.

Note that **WS_USERNAME_CREDENTIAL** and its concrete subtypes
are used with the WS-Security [WS_USERNAME_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_username_message_security_binding).
They are best suitable for application-level username/password pairs, such as
those used for online customer accounts. The usernames and passwords specified
are not interpreted by the security runtime, and are merely carried
client-to-server for authentication by the specified server-side
username/password validator specified by the application.

In contrast, the [WS_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_windows_integrated_auth_credential) and
its concrete subtypes are used for Windows Integrated Authentication
and the security bindings that use it.

## Members

### `credentialType`

The selector for the type of the username credential.