# WsCreateFaultFromError function

## Description

Constructs a [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) from a specified error object.

## Parameters

### `error` [in]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure representing the error object from which to construct the fault.

### `faultErrorCode` [in]

The HRESULT error code returned from the function that failed.
The HRESULT value cannot be a success code.

This error code is never included in the fault directly, but is used as a fallback mechanism for creating a fault string if the error object does not contain any error strings.

### `faultDisclosure` [in]

[WS_FAULT_DISCLOSURE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_disclosure) enumeration that controls
what information is copied from
the error object to the fault object.

### `heap` [in]

Pointer to a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure representing the [heap](https://learn.microsoft.com/windows/desktop/wsw/heap) from which to allocate memory for the returned fault object.

### `fault` [out]

Pointer to a [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) structure representing the returned fault object. The fields of the fault object are good until
[WsFreeHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreeheap) or [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) is called to release the specified heap resources.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If the error object contains a fault (that is, the WS_FAULT_ERROR_PROPERTY_FAULT value of [WS_FAULT_ERROR_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_error_property_id) is non-**NULL**), then that fault is selected to construct the returned fault.

If the error object does not contain a fault (WS_FAULT_ERROR_PROPERTY_FAULT is **NULL**), a generic fault with a generic fault code (and no reason text) is selected to construct the returned fault.

If the selected fault does not include any reason text, the fault reason
text is constructed according to the value of *disclosure* parameter:

* WS_FULL_FAULT_DISCLOSURE
  All the error strings present in the error object are appended together
  to form the reason text. If there are no strings, the string associated
  with the *errorCode* parameter is used.
* WS_MINIMAL_FAULT_DISCLOSURE
  A generic error string is used.

By default, the
language of any language-dependent information in the error object is the current
user default UI language. However, you can change the language by setting
the WS_ERROR_PROPERTY_LANGID property. See the [WS_ERROR_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id) enumeration.