# WsWriteBody function

## Description

Writes a value in the body of a message.
This is a helper function that serializes a value to the XML Writer
of the message.
The message state must be set to **WS_MESSAGE_STATE_WRITING**. This function
does not cause any state transitions.

## Parameters

### `message` [in]

A pointer to the **Message** object for writing to. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.

### `bodyDescription` [in]

A pointer to information describing how to write the value.

### `writeOption` [in]

Determines whether the value is required and how the value is allocated.

**Note** See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for more information.

### `value`

A void pointer to the value to write.

### `valueSize` [in]

The size in bytes of the value to write.
If the value is **NULL** the size should be 0.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This functions supports the following scenarios, based on the contents
of the [WS_ELEMENT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_element_description) supplied:

* Writing a single element. In this case, the elementLocalName and elementNs
  fields of the **WS_ELEMENT_DESCRIPTION** should be set to the local name
  and namespace of the element to write, and the type and type description represents
  the type of the value being serialized. If using **WS_FAULT_TYPE** or
  **WS_ENDPOINT_ADDRESS_TYPE**, it is not necessary to specify the local name,
  namespace, or type description (they will default appropriately based on the
  envelope/addressing version of the message).
* Writing multiple elements as a single value. In this case, the elementLocalName and elementNs
  fields of the **WS_ELEMENT_DESCRIPTION** should be set to **NULL**, and a **WS_STRUCT_TYPE** and **WS_STRUCT_DESCRIPTION** should be specified. In this case, each field of the
  structure value being serialized should correspond to element(s) to write within the body.
* Writing multiple elements as multiple values. Writing multiple distinct values can be
  accomplished by simply calling the function multiple times.