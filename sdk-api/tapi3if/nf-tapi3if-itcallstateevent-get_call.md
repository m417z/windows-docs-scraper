# ITCallStateEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the call information interface for the call on which the event has occurred.

## Parameters

### `ppCallInfo` [out]

Pointer to
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCallInfo* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallStateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallstateevent)