# HttpQueryServerSessionProperty function

## Description

The **HttpQueryServerSessionProperty** function queries a server property on the specified server session.

## Parameters

### `ServerSessionId` [in]

The server session for which the property setting is returned.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration that describes the property type that is queried. This can be one of the following.

| Property | Meaning |
| --- | --- |
| **HttpServerStateProperty** | Queries the current state of the server session. |
| **HttpServerTimeoutsProperty** | Queries the server session connection timeout limits. |
| **HttpServerQosProperty** | Queries the bandwidth throttling for the server session. By default, the HTTP Server API does not limit bandwidth. |
| **HttpServerAuthenticationProperty** | Queries kernel mode server-side authentication for the Basic, NTLM, Negotiate, and Digest authentication schemes. |
| **HttpServerChannelBindProperty** | Queries the channel binding token (CBT) properties. |

### `PropertyInformation` [out]

A pointer to the buffer that receives the property data.

*pPropertyInformation* points to one of the following property data structures based on the property that is set.

| Property | Structure |
| --- | --- |
| HttpServerStateProperty | [HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info) |
| HttpServerQosProperty | [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) |
| HttpServerTimeoutsProperty | [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) |
| HttpServerAuthenticationProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerChannelBindProperty | [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

### `ReturnLength` [out, optional]

The number, in bytes, returned in the *pPropertyInformation* buffer.

If the output buffer is too small, the call fails with a return value of **ERROR_MORE_DATA**. The value pointed to by *pReturnLength* can be used to determine the minimum length of the buffer required for the call to succeed.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The property type specified in the *Property* parameter is not supported for server sessions.<br><br>The *ServerSessionId* parameter does not contain a valid server session.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The application does not have permission to query the server session properties. Only the application that created the server session can query the properties. |
| **ERROR_MORE_DATA** | The size, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter is too small to receive the property data. On exit call the function again with a buffer at least as large as the size pointed to by *pReturnLength* on exit. |

## Remarks

Querying the **HttpServerLoggingProperty** is not supported.

The *pPropertyInformation* parameter points to the configuration structure for the property type that is queried. The *PropertyInformationLength* parameter specifies the size, in bytes, of the configuration structure. For example, when querying the **HttpServerTimeoutsProperty** the *pPropertyInformation* parameter must point to a buffer that is at least the size of the [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) structure.

 To specify the HttpServerQosProperty property in the *pPropertyInformation* parameter, set **QosType** to **HttpQosSettingTypeBandwidth** inside the [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure, and pass a pointer to this structure in the parameter.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseserversession)

[HttpCreateServerSession](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateserversession)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)