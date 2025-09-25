# HttpSetServerSessionProperty function

## Description

The **HttpSetServerSessionProperty** function sets a new server session property or modifies an existing property on the specified server session.

## Parameters

### `ServerSessionId` [in]

The server session for which the property is set.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration that describes the property type that is set. This can be one of the following.

| Property | Meaning |
| --- | --- |
| **HttpServerStateProperty** | Modifies or sets the state of the server session. The state can be either enabled or disabled; the default state is enabled. |
| **HttpServerTimeoutsProperty** | Modifies or sets the server session connection timeout limits. |
| **HttpServerQosProperty** | Modifies or sets the bandwidth throttling for the server session. By default, the HTTP Server API does not limit bandwidth. <br><br>**Note** This value maps to the generic [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure with **QosType** set to **HttpQosSettingTypeBandwidth**. |
| **HttpServerLoggingProperty** | Enables or disables logging for the server session. This property sets only centralized W3C and centralized binary logging. By default, logging is not enabled. |
| **HttpServerAuthenticationProperty** | Enables kernel mode server side authentication for the Basic, NTLM, Negotiate, and Digest authentication schemes. |
| **HttpServerExtendedAuthenticationProperty** | Enables kernel mode server side authentication for the Kerberos authentication scheme. |
| **HttpServerChannelBindProperty** | Enables server side authentication that uses a channel binding token (CBT). |

### `PropertyInformation` [in]

A pointer to the buffer that contains the property data.

*pPropertyInformation* points to a property data structure, listed in the following table, based on the property that is set.

| Property | Structure |
| --- | --- |
| HttpServerStateProperty | [HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info) |
| HttpServerLoggingProperty | [HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info) |
| HttpServerQosProperty | [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) |
| HttpServerTimeoutsProperty | [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) |
| HttpServerAuthenticationProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerExtendedAuthenticationProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerChannelBindProperty | [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The property type specified in the *Property* parameter is not supported for server sessions.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The *ServerSessionId* parameter does not contain a valid server session.<br><br>The application does not have permission to set the server session properties. Only the application that created the server session can set the properties. |

## Remarks

Server sessions are top level configuration containers for configuration data that applies to all of the URL groups created under them. The server session is created with [HttpCreateServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateserversession).

The *pPropertyInformation* parameter points to the configuration structure for the property type that is set. The *PropertyInformationLength* parameter specifies the size, in bytes, of the configuration structure. For example, when setting the **HttpServerTimeoutsProperty** the *pPropertyInformation* parameter must point to a buffer that is at least equal to the size of the [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) structure.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession)

[HttpCreateServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateserversession)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)