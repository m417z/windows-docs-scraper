# HttpInitialize function

## Description

The **HttpInitialize** function initializes the HTTP Server API driver, starts it, if it has not already been started, and allocates data structures for the calling application to support response-queue creation and other operations. Call this function before calling any other functions in the HTTP Server API.

## Parameters

### `Version` [in]

HTTP version. This parameter is an
[HTTPAPI_VERSION](https://learn.microsoft.com/windows/win32/api/http/ns-http-httpapi_version) structure. For the current version, declare an instance of the structure and set it to the pre-defined value **HTTPAPI_VERSION_1** before passing it to
**HttpInitialize**.

### `Flags` [in]

Initialization options, which can include one or both of the following values.

| Value | Meaning |
| --- | --- |
| **HTTP_INITIALIZE_CONFIG** | Perform initialization for applications that use the HTTP configuration functions, [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpsetserviceconfiguration), [HttpQueryServiceConfiguration](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpqueryserviceconfiguration), [HttpDeleteServiceConfiguration](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpdeleteserviceconfiguration), and [HttpIsFeatureSupported](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpisfeaturesupported). |
| **HTTP_INITIALIZE_SERVER** | Perform initialization for applications that use the HTTP Server API. |

### `pReserved` [in, out]

This parameter is reserved, and must be **NULL**.

## Return value

If the function succeeds, then the return value is **NO_ERROR**.

If the function fails, then the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *Flags* parameter contains an unsupported value. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/win32/debug/system-error-codes) defined in WinError.h. |

## Remarks

Call
[HttpTerminate](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpterminate) when the application completes. All the same flags that were passed to
**HttpInitialize** in the *Flags* parameter must also be passed to
**HttpTerminate**. An application can call
**HttpInitialize** repeatedly, provided that each call to
**HttpInitialize** is later matched by a corresponding call to
**HttpTerminate**.

## See also

* [HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/win32/http/http-server-api-version-1-0-functions)
* [HttpTerminate](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpterminate)