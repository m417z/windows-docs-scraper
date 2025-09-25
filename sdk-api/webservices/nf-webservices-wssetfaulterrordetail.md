# WsSetFaultErrorDetail function

## Description

Write the fault detail stored in a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

## Parameters

### `error` [in]

The error object that will contain the fault information.

### `faultDetailDescription` [in]

A pointer to a description of the fault detail.

If the action field of the fault detail description is non-**NULL**,
then it is set as the [WS_FAULT_ERROR_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_error_property_id) of the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error).

The element description of the fault detail description
describes the format of the element in the fault detail.

### `writeOption` [in]

Information about how the value is allocated.
See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for more information.

### `value`

A pointer to the value to serialize.

### `valueSize` [in]

The size of the value being serialized, in bytes.

If the value is **NULL**, then the size should be 0.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |

## Remarks

This API will serialize the value of the detail field of
the [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) stored in the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

This functions supports the following scenarios, based on the contents
of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_fault_detail_description) in the [WS_FAULT_DETAIL_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault_detail_description) supplied:

* Writing a single element. In this case, the elementLocalName and elementNs
  fields of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) should be set to the local name
  and namespace of the element to write, and the type and type description represents
  the type of the value being serialized.
* Writing multiple elements as a single value. In this case, the elementLocalName and elementNs
  fields of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) should be set to **NULL**, and a [WS_STRUCT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and [WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description) should be specified. Each field of the
  structure value being serialized should correspond to element(s) to write within the fault detail.
  The writeOption parameter must be either [WS_WRITE_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) or
  **WS_WRITE_REQUIRED_POINTER**.