# ITCallHub::get_State

## Description

The
**get_State** method gets the current state of the CallHub.

## Parameters

### `pState` [out]

Pointer to
[CALLHUB_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callhub_state) indicator of state.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pState* parameter is not a valid pointer. |

## See also

[CALLHUB_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callhub_state)

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)