# ITQOSEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface for the call on which the QOS event occurred.

## Parameters

### `ppCall` [out]

Points to
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCall* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by **tapi3.itqosevent_get_call**. The application must call **Release** on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface to free resources associated with it.

## See also

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)