# HttpSetUrlGroupProperty function

## Description

The **HttpSetUrlGroupProperty** function sets a new property or modifies an existing property on the specified URL Group.

## Parameters

### `UrlGroupId` [in]

The ID of the URL Group for which the property is set.

### `Property` [in]

A member of the [HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) enumeration that describes the property type that is modified or set. This can be one of the following:

| Property | Meaning |
| --- | --- |
| **HttpServerAuthenticationProperty** | Enables server-side authentication for the URL Group using the Basic, NTLM, Negotiate, and Digest authentication schemes. |
| **HttpServerExtendedAuthenticationProperty** | Enables server-side authentication for the URL Group using the Kerberos authentication scheme. |
| **HttpServerQosProperty** | This value maps to the generic [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure with **QosType** set to either **HttpQosSettingTypeBandwidth** or **HttpQosSettingTypeConnectionLimit**. If **HttpQosSettingTypeBandwidth**, modifies or sets the bandwidth throttling for the URL Group. If **HttpQosSettingTypeConnectionLimit**, modifies or sets the maximum number of outstanding connections served for a URL Group at any time. |
| **HttpServerBindingProperty** | Modifies or sets the URL Group association with a request queue. |
| **HttpServerLoggingProperty** | Modifies or sets logging for the URL Group. |
| **HttpServerStateProperty** | Modifies or sets the state of the URL Group. The state can be either enabled or disabled. |
| **HttpServerTimeoutsProperty** | Modifies or sets the connection timeout limits for the URL Group. |
| **HttpServerChannelBindProperty** | Enables server side authentication that uses a channel binding token (CBT). |

### `PropertyInformation` [in]

A pointer to the buffer that contains the property information.

*pPropertyInformation* points to one of the following property information structures based on the property that is set.

| Property | Structure |
| --- | --- |
| HttpServerAuthenticatonProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerExtendedAuthenticationProperty | [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) |
| HttpServerQosProperty | [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) |
| HttpServerBindingProperty | [HTTP_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_binding_info) |
| HttpServerLoggingProperty | [HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info) |
| HttpServerStateProperty | [HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info) |
| HttpServerTimeoutsProperty | [HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info) |
| HttpServerChannelBindProperty | [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) |

### `PropertyInformationLength` [in]

The length, in bytes, of the buffer pointed to by the *pPropertyInformation* parameter.

## Return value

If the function succeeds, it returns **NO_ERROR**.

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The property type specified in the *Property* parameter is not supported for URL Groups.<br><br>The *pPropertyInformation* parameter is **NULL**.<br><br>The *PropertyInformationLength* parameter is zero.<br><br>The *UrlGroupId* parameter does not contain a valid server session.<br><br>The application does not have permission to set the URL Group properties. Only the application that created the URL Group can set the properties. |

## Remarks

After the URL Group is created it must be associated with a request queue to receive requests. To associate the URL Group with a request queue, the application calls **HttpSetUrlGroupProperty** with the **HttpServerBindingProperty** property. If this property is not set, matching requests for the URL Group are not delivered to a request queue and the HTTP Server API generates a 503 response.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup)

[HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)