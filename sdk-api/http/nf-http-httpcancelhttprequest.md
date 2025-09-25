# HttpCancelHttpRequest function

## Description

The **HttpCancelHttpRequest** function cancels a specified request.

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue from which the request came.

### `RequestId` [in]

The ID of the request to be canceled.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure; for synchronous calls, set it to **NULL**.

## Return value

If the function succeeds, it returns **NO_ERROR**.

## Remarks

When the **HttpCancelHttpRequest** function is used to cancel a request, the underlying transport connection used for the request will be closed.

## See also

[HTTP Server API Version 2.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-functions)

[Processing Requests](https://learn.microsoft.com/windows/desktop/Http/processing-requests)