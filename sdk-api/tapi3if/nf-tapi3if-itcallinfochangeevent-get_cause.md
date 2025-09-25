# ITCallInfoChangeEvent::get_Cause

## Description

The
**get_Cause** method gets a
[CALLINFOCHANGE_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfochange_cause) description of the change.

## Parameters

### `pCIC` [out]

Pointer to
[CALLINFOCHANGE_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfochange_cause) description of the call event that has occurred.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCIC* parameter is not a valid pointer. |

## See also

[CALLINFOCHANGE_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfochange_cause)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfoChangeEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfochangeevent)