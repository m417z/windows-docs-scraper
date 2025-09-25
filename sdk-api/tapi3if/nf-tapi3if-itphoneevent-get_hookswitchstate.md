# ITPhoneEvent::get_HookSwitchState

## Description

The
**get_HookSwitchState** method returns a
[PHONE_HOOK_SWITCH_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_state) value specifying the state to which the hookswitch has transitioned. This information is available only when the
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) method returns PE_HOOKSWITCH.

## Parameters

### `pState` [out]

Pointer to the
[PHONE_HOOK_SWITCH_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_state) descriptor of the current hookswitch state.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)