# ITCallStateEvent::get_State

## Description

The
**get_State** method gets information on the new call state.

## Parameters

### `pCallState` [out]

Pointer to
[CALL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) constant.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallState* parameter is not a valid pointer. |

## See also

[CALL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallStateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallstateevent)