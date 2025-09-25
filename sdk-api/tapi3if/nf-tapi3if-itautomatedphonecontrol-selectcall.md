# ITAutomatedPhoneControl::SelectCall

## Description

The
**SelectCall** method selects the current phone object onto the Call object pointed to by the *pCall* parameter.

## Parameters

### `pCall` [in]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

### `fSelectDefaultTerminals` [in]

If VARIANT_TRUE, use default terminals. For more information, see the following Remarks section.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The application must have owner privilege on both the call and the phone for this method to return success. If the phone is not already open with owner privilege, this method fails.

If the *fSelectDefaultTerminals* parameter is set to VARIANT_TRUE, this method retrieves all the default terminals associated with the phone and attempts to select them on the call. If instantiation of one of the terminals fails, or if selection of one of the terminals on the call fails, then the entire
**SelectCall** method will return failure, and the call will not be selected on the phone. If this is not the required behavior for an application, then the application should pass in VARIANT_FALSE for the *fSelectDefaultTerminals* parameter and handle terminal selection separately.

On successful completion of this method, the phone object keeps a reference to the call object (that is, it calls the
[AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)).

For Windows XP, only one call at a time can be selected on a phone. Future versions of TAPI may support simultaneous selection of multiple calls for use with phones that support multiple call appearances.

Note that a call can be unselected in two ways: (1) the application can invoke
[ITAutomatedPhoneControl::UnselectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-unselectcall), or (2) the phone object itself can invoke **ITAutomatedPhoneControl::UnselectCall**. See the following list for information on when this happens.

After this method completes successfully, the following handling is performed on the selected call:

* When the phone goes onhook, the phone object calls
  [ITBasicCallControl::Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect) on any currently handled call that is not already in the CS_DISCONNECTED call state.
* If a selected call reaches the CS_DISCONNECTED call state, then the phone object automatically unselects the call using the
  [ITAutomatedPhoneControl::UnselectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-unselectcall) method.
* If the phone is closed, any selected call is automatically unselected from that phone.
* When the phone goes offhook, or a call is selected when the phone is offhook, the phone object calls
  [ITBasicCallControl::Answer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-answer) on the currently handled call if it is in the CS_OFFERING call state.
* The phone object calls
  [ITAutomatedPhoneControl::StartTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-starttone)( PT_RINGBACK, 0 ) on itself when a call is selected on it in the CS_INPROGRESS call state and the phone is offhook, or when a call that has been selected on the phone enters the CS_INPROGRESS call state and the phone is offhook.
* The phone object calls
  [ITAutomatedPhoneControl::StopTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stoptone) on itself when a call is selected on it in the CS_CONNECTED call state, or when a call that has been selected on the phone enters the CS_CONNECTED call state.
* The phone object calls
  [ITAutomatedPhoneControl::StartRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-startringer)( 0, 0 ) on itself when a call is selected on it in the CS_OFFERING, CS_INPROGRESS, or CS_CONNECTED call state and the phone is onhook. This also occurs when a call that has been selected on the phone enters the CS_OFFERING, CS_INPROGRESS, or CS_CONNECTED call state and the phone is onhook.

Depending on the circumstances, the phone object performs one of the following actions when a call is selected on it in the CS_DISCONNECTED call state, or when a call that has been selected on the phone enters the CS_DISCONNECTED call state.

* If the phone is onhook, then the phone object calls
  [ITAutomatedPhoneControl::StopRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stopringer) on itself.
* If the phone is offhook and the CS_DISCONNECTED call state event has cause equal to CEC_DISCONNECT_BUSY, then the phone object calls
  [ITAutomatedPhoneControl::StartTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-starttone)( PT_BUSY, 0 ).
* If the phone is offhook and the CS_DISCONNECTED call state event has cause equal to CEC_DISCONNECT_NORMAL, then the phone object calls
  [ITAutomatedPhoneControl::StopTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stoptone).
* If the phone is offhook and the CS_DISCONNECTED call state event has neither cause CEC_DISCONNECT_BUSY nor cause CEC_DISCONNECT_NORMAL, then the phone object calls
  [ITAutomatedPhoneControl::StartTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-starttone)( PT_ERROR, 0 ).

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)