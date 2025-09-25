# ITCallInfo::get_Privilege

## Description

The
**get_Privilege** method gets the
[call privilege](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_privilege) of the application for the current call, such as CP_MONITOR.

## Parameters

### `pPrivilege` [out]

Pointer to
[CALL_PRIVILEGE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_privilege).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pPrivilege* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

**TAPI 2.1 Cross-Reference:** [LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

## See also

[CALL_PRIVILEGE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_privilege)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)