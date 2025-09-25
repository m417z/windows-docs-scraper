# ITAutomatedPhoneControl::UnselectCall

## Description

The
**UnselectCall** method removes the specified call from this phone object, releasing the phone object's reference to the call object. The phone object performs no further call control handling on the call object once the call object has been successfully unselected. See
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) for more information.

## Parameters

### `pCall` [in]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)