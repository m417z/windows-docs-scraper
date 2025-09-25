# WsReadBody function

## Description

This is a helper function that deserializes a value from the XML Readerof the message.
The [WS_MESSAGE_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) must be set to **WS_MESSAGE_STATE_READING**. This function does
not cause any state transitions.

## Parameters

### `message` [in]

A pointer to the **Message** object to read the body from. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.

### `bodyDescription` [in]

A pointer to the object encapsulating the metadata that describes the mapping of the value to an element.

### `readOption` [in]

Determines whether the value is required and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

### `heap` [in, optional]

A pointer to the **Heap** object to read the element into. The pointer must reference a valid [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) object.

### `value`

The interpretation of the data referenced by this parameter depends on the **WS_READ_OPTION**.

### `valueSize` [in]

The interpretation of the value of this parameter depends on the **WS_READ_OPTION**.

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
of the **WS_ELEMENT_DESCRIPTION** supplied:

* Reading a single element. In this case, the elementLocalName and elementNs
  fields of the **WS_ELEMENT_DESCRIPTION** should be set to the local name
  and namespace of the element to read, and the type and type description represents
  the type of the value being deserialized. If using **WS_FAULT_TYPE** or
  **WS_ENDPOINT_ADDRESS_TYPE** it is not necessary to specify the local name,
  namespace, or type description (they will default appropriately based on the
  envelope/addressing version of the message).
* Reading multiple elements as a single value. In this case, the elementLocalName and elementNs
  fields of the **WS_ELEMENT_DESCRIPTION** should be set to **NULL**, and a **WS_STRUCT_TYPE** and [WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description) should be specified. In this case, each field of the
  structure value being deserialized should correspond to element(s) to read within the body.
* Reading multiple elements as multiple values. Reading multiple distinct values can be
  accomplished by simply calling the function multiple times.