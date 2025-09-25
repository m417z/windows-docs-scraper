# HttpQueryUrlGroupProperty function

## Description

The **HttpQueryUrlGroupProperty** function queries a property on the specified URL Group.

## Parameters

### `UrlGroupId` [in]

The ID of the URL Group for which the property setting is returned.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration that describes the property type that is queried. This can be one of the following:

| Property | Meaning |
| --- | --- |
| **HttpServerAuthenticationProperty** | Queries the enabled server-side authentication schemes. |
| **HttpServerTimeoutsProperty** | Queries the URL Group connection timeout limits. |
| **HttpServerStateProperty** | Queries the current state of the URL Group. The state can be either enabled or disabled. |
| **HttpServerQosProperty** | This value maps to the generic [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure with **QosType** set to either **HttpQosSettingTypeBandwidth** or **HttpQosSettingTypeConnectionLimit**. If **HttpQosSettingTypeBandwidth**, queries the bandwidth throttling for the URL Group. If **HttpQosSettingTypeConnectionLimit**, queries the maximum number of outstanding connections served for a URL group at any time. |
| **HttpServerChannelBindProperty** | Queries the channel binding token (CBT) properties. |

### `PropertyInformation` [out]

A pointer to the buffer that receives the property information.

*pPropertyInformation* points to one of the following property information structures based on the property that is queried.

| Property | Structure |
| --- | --- |
| HttpServerStateProperty | [HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info) |
| HttpServerAuthenticationProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerQosProperty | [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) |
| HttpServerTimeoutsProperty | [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) |
| HttpServerChannelBindProperty | [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

### `ReturnLength` [out, optional]

The size, in bytes, returned in the *pPropertyInformation* buffer.

If the output buffer is too small, the call fails with a return value of **ERROR_MORE_DATA**. The value pointed to by *pReturnLength* can be used to determine the minimum length of the buffer required for the call to succeed.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The property type specified in the *Property* parameter is not supported for URL Groups.<br><br>The *UrlGroupId* parameter does not identify a valid server URL Group.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The application does not have permission to query the URL Group properties. Only the application that created the URL Group can query the properties. |
| **ERROR_MORE_DATA** | The size, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter is too small to receive the property information. Call the function again with a buffer at least as large as the size pointed to by *pReturnLength* on exit. |

## Remarks

Querying the **HttpServerLoggingProperty** is not supported.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup)

[HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)