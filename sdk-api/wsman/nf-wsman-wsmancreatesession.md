# WSManCreateSession function

## Description

Creates a session object.

## Parameters

### `apiHandle` [in]

Specifies the API handle returned by the [WSManInitialize](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmaninitialize) call. This parameter cannot be **NULL**.

### `connection` [in, optional]

Indicates to which protocol and agent to connect. If this parameter is **NULL**, the
connection will default to localhost (127.0.0.1). This parameter can be a simple host name or a complete URL.
The format is the following:

[transport://]host[:port][/prefix] where:

| Element | Description |
| --- | --- |
| transport | Either HTTP or HTTPS. Default is HTTP. |
| host | Can be in a DNS name, NetBIOS name, or IP address. |
| port | Defaults to 80 for HTTP and to 443 for HTTPS. The defaults can be changed in the local configuration. |
| prefix | Any string. Default is "wsman". The default can be changed in the local configuration. |

### `flags`

Reserved for future use. Must be zero.

### `serverAuthenticationCredentials` [in, optional]

Defines the authentication method such as Negotiate, Kerberos, Digest, Basic, or client certificate. If the authentication mechanism is Negotiate, Kerberos, Digest, or Basic, the structure can also contain the credentials used for authentication. If client certificate authentication is used, the certificate thumbprint must be specified.

If credentials are specified, this parameter contains the user name and password of a local account or domain account. If this parameter is **NULL**, the default credentials are used. The default credentials are the credentials that the current thread is executing under. The client must explicitly specify the credentials when Basic or Digest authentication is used. If explicit credentials are used, both the user name and the password must be valid. For more information about the authentication credentials, see the [WSMAN_AUTHENTICATION_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_authentication_credentials) structure.

### `proxyInfo` [in, optional]

A pointer to a [WSMAN_PROXY_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_proxy_info) structure that specifies proxy information. This value can be **NULL**.

### `session` [out]

Defines the session handle that uniquely identifies the session. This parameter cannot be **NULL**. This handle should be closed by calling the [WSManCloseSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosesession) method.

## Return value

If the function succeeds, the return value is zero. Otherwise, the return value is an error code.