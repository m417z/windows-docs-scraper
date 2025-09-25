# ITCallMediaEvent::get_Call

## Description

The
**get_Call** method gets an
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface pointer for the call object associated with this event.

## Parameters

### `ppCallInfo` [out]

Pointer to
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppCallInfo* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by **ITCallMediaEvent::get_Call**. The application must call **Release** on
**ITCallInfo** to free resources associated with it.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)