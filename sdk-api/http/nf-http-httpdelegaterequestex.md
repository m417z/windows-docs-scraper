## Description

Delegates a request from the source request queue to the target request queue.

## Parameters

### `RequestQueueHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the source request queue.

### `DelegateQueueHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the target request queue.

### `RequestId`

Type: \_In\_ **HTTP_REQUEST_ID**

A unique request ID received with [HttpReceiveHttpRequest](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpreceivehttprequest).

### `DelegateUrlGroupId`

Type: \_In\_ **HTTP_URL_GROUP_ID**

The url group id of the target url group.

### `PropertyInfoSetSize`

Type: \_In\_ **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of entries in the *PropertyInfoSet* array.

### `PropertyInfoSet`

Type: \_In\_ [**PHTTP_DELEGATE_REQUEST_PROPERTY_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_delegate_request_property_info)**

An array of properties to be set on request when delegating.

## Return value

A **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)** containing an [NTSTATUS](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/87fba13e-bf06-450e-83b1-9241dc81e781) completion status.

## Remarks

## See also