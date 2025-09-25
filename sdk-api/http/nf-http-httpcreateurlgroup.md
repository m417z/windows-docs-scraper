# HttpCreateUrlGroup function

## Description

The **HttpCreateUrlGroup** function creates a URL Group under the specified server session.

## Parameters

### `ServerSessionId` [in]

The identifier of the server session under which the URL Group is created.

### `pUrlGroupId` [out]

A pointer to the variable that receives the ID of the URL Group.

### `Reserved` [in]

Reserved. Must be zero.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *ServerSessionId* parameter indicates a non-existing Server Session.<br><br>The *pUrlGroupId* parameter is null.<br><br>The *Reserved* parameter is non-zero. |

## Remarks

URL Groups are configuration containers for a set of URLs. They are created under the server session and inherit the configuration settings of the server session. When a configuration parameter is set on the URL Group, it overrides the configuration set on the server session. For more information about the setting configurations for the URL Group, see [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty).

After the URL group is created it must be associated with a request queue to receive requests. To associate the URL Group with a request queue, the application calls [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty) with the **HttpServerBindingProperty** property. If this property is not set, matching requests for the URL Group are not delivered to a request queue and the HTTP Server API generates a 503 response.

The URL Group association with a request queue is dynamic. The association with the servers session cannot be changed until either the server session or the URL Group is deleted. When a server session is deleted all of the associated URL Groups are also automatically closed.

The URL Group is initially created as an empty group. URLs must be added to the group by calling [HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup).

Application may create multiple URL Groups for the following reasons:

* To set distinct configurations for different portions of URL name space on which it is listening.
* To set separate request queues for different portions of URL name space on which it is listening.

Applications should combine URLs into groups as much as possible; otherwise performance will degrade and increased memory consumption of the system will affect the scalability.

The HTTP Server API does not support asynchronous I/O on URL Groups.

When the URL group is no longer needed or before the application terminates it must delete the URL Group by calling [HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup).

The URL Group is created with the same version as the server session under which it is created.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpAddUrlToUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpaddurltourlgroup)

[HttpCloseUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloseurlgroup)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpRemoveUrlFromUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpremoveurlfromurlgroup)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)