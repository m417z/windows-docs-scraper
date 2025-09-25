# ITCallMediaEvent::get_Error

## Description

The
**get_Error** method gets the error associated with the media event, if any.

## Parameters

### `phrError` [out]

Pointer to error.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *phrError* parameter is not a valid pointer. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)