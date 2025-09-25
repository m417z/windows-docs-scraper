# ITCallInfo::get_CallState

## Description

The
**get_CallState** method gets a pointer to the current
[call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state), such as CS_IDLE.

## Parameters

### `pCallState` [out]

Pointer to variable containing current
[CALL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) type.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pCallState* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

**TAPI 2.1 Cross-References:** [LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus), [ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo), **dwMediaMode** member of [LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure, [Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

## See also

[CALL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)