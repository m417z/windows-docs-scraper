# HttpCreateRequestQueue function

## Description

The **HttpCreateRequestQueue** function creates a new request queue or opens an existing request queue.

 This function replaces the HTTP version 1.0 [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

## Parameters

### `Version` [in]

An HTTPAPI_VERSION structure indicating the request queue version. For version 2.0, declare an instance of the structure and set it to the predefined value HTTPAPI_VERSION_2 before passing it to **HttpCreateRequestQueue**.

The version must be 2.0; **HttpCreateRequestQueue** does not support version 1.0 request queues.

### `Name` [in, optional]

The name of the request queue. The length, in bytes, cannot exceed MAX_PATH.

 The optional name parameter allows other processes to access the request queue by name.

### `SecurityAttributes` [in, optional]

A pointer to the [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that contains the access permissions for the request queue.

This parameter must be **NULL** when opening an existing request queue.

### `Flags` [in, optional]

The flags parameter defines the scope of the request queue. This parameter can be one or more of the following:

| Value | Meaning |
| --- | --- |
| **HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER** | The handle to the request queue created using this flag cannot be used to perform I/O operations. This flag can be set only when the request queue handle is created. |
| **HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING** | The **HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING** flag allows applications to open an existing request queue by name and retrieve the request queue handle. The *pName* parameter must contain a valid request queue name; it cannot be **NULL**. |

### `RequestQueueHandle` [out]

A pointer to a variable that receives a handle to the request queue. This parameter must contain a valid pointer; it cannot be **NULL**.

## Return value

If the function succeeds, it returns **NO_ERROR**

If the function fails, it returns one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_REVISION_MISMATCH** | The *Version* parameter contains an invalid version. |
| **ERROR_INVALID_PARAMETER** | The length, in bytes, of the request queue name cannot exceed MAX_PATH.<br><br>The *pSecurityAttributes* parameter must be **NULL** when opening an existing request queue.<br><br>The **HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER** can only be set when the request queue is created.<br><br>The **HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING** can only be set when the application has permission to open an existing request queue. In this case, the *pReqQueueHandle* parameter must be a valid pointer, and the *pName* parameter must contain a valid request queue name; it cannot be **NULL**.<br><br>The *pReqQueueHandle* parameter returned by [HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) is **NULL**. |
| **ERROR_ALREADY_EXISTS** | The *pName* parameter conflicts with an existing request queue that contains an identical name. |
| **ERROR_ACCESS_DENIED** | The calling process does not have a permission to open the request queue. |
| **ERROR_DLL_INIT_FAILED** | The application has not called [HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) prior to calling [HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue). |

## Remarks

The HTTP Server API supports existing applications using the version 1.0 request queues, however, new development with the HTTP Server API should use **HttpCreateRequestQueue** to create request queues; [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) should not be used. The version 2.0 API are only compatible with the version 2.0 request queues created by **HttpCreateRequestQueue**.

The HTTP version 2 request queues require manual configuration; the application must create the URL Groups and associate one or more URL Group with the request queue by calling [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty) with the **HttpServerBindingProperty**. The application configures the request queue by calling [HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty) with the desired configuration in the *Property* parameter. For more information about creating and configuring URL groups, see [HttpCreateUrlGroup](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreateurlgroup) and **HttpSetUrlGroupProperty**.

Security attributes may be supplied in *pSecurityAttributes* parameter only when the request queue is created. Only the application that creates the request queue can set Access Control Lists (ACLs) on the request queue handle to allow processes (other than the creator application) permission to open, receive requests, and send responses on the request queue handle. By default, applications are not allowed to open a request queue unless they have been granted permission in the ACL.

The creator process can optionally use the **HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER** flag to indicate that it does not want to receive http requests.

**HttpCreateRequestQueue** allows applications to open an existing request queue with the **HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING** flag and retrieve the handle to the request queue. Non-controller applications can use this handle to perform HTTP I/O operations. Only the application that creates the request queue can set properties on it by calling the [HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty).

The handle to the request queue created by **HttpCreateRequestQueue** must be closed by calling [HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue) before the application terminates or when the session is no longer required.

Applications must call [HttpInitialize](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpinitialize) prior to calling **HttpCreateRequestQueue**.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[HttpCloseRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcloserequestqueue)

[HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpShutdownRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpshutdownrequestqueue)