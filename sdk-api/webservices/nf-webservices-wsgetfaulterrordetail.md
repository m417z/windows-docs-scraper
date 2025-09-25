# WsGetFaultErrorDetail function

## Description

Read the fault detail stored in a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

## Parameters

### `error` [in]

The error object that contains the fault information.

### `faultDetailDescription` [in]

A pointer to a description of the fault detail element.

The action value of the fault detail description is used as a filter
value to match against the action of the fault. If both action
strings are specified (the action value of the fault detail description
is not **NULL** and the action value [WS_FAULT_ERROR_PROPERTY_ACTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_fault_error_property_id) in the
[WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) has a length greater than zero), then the action
strings are compared to determine a match. If there is a match, then the
function will then try to deserialize the detail element.

The element description of the fault detail description is used to
describe the format of the element in the fault detail.

### `readOption` [in]

Whether the element is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

### `heap` [in, optional]

The heap to store the deserialized values in.

### `value`

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `valueSize` [in]

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **WS_E_QUOTA_EXCEEDED** | The size quota of the heap was exceeded. |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

This API deserializes the value from the detail field of
the [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault) stored in the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object.

This functions supports the following scenarios, based on the contents
of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_fault_detail_description) in the [WS_FAULT_DETAIL_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault_detail_description) supplied:

* Reading a single element.
  In this case, the elementLocalName and elementNs
  fields of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) should be set to the local name
  and namespace of the element to read, and the type and type description represents
  the type of the value being deserialized.

  Since different faults with different detail formats may be expected
  from a service, this function can be called in succession to try to
  read each type of detail. In this case, the [WS_READ_OPTIONAL_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) value can be specified, which will return a **NULL** pointer if the element name
  in the fault detail does not match the expected value.
* Reading multiple elements as a single value.
  In this case, the elementLocalName and elementNs
  fields of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) should be set to **NULL**, and a [WS_STRUCT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and [WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description) should be specified. Each field of the
  structure value being deserialized should correspond to element(s) to read within the body.
  The readOption parameter must be [WS_READ_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) or **WS_READ_REQUIRED_POINTER**.