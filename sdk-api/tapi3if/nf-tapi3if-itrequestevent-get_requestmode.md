# ITRequestEvent::get_RequestMode

## Description

The
**get_RequestMode** method gets the mode of the request.

## Parameters

### `plRequestMode` [out]

Pointer to the request mode.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plRequestMode* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)