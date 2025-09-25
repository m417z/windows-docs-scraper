# ITToneTerminalEvent::get_Call

## Description

The
**get_Call** method retrieves an interface pointer for the call object on which the event occurred.

## Parameters

### `ppCall` [out]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by **ITToneTerminalEvent::get_Call**. The application must call **Release** on the
**ITCallInfo** interface to free resources associated with it.

## See also

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITToneTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittoneterminalevent)