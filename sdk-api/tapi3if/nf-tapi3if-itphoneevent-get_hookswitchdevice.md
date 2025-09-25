# ITPhoneEvent::get_HookSwitchDevice

## Description

The
**get_HookSwitchDevice** method returns a
[PHONE_HOOK_SWITCH_DEVICE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_device) value specifying the hookswitch device that changed state. This information is available only when the
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) method returns PE_HOOKSWITCH.

## Parameters

### `pDevice` [out]

Pointer to the
[PHONE_HOOK_SWITCH_DEVICE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_device) descriptor of the type of device that has changed hookswitch state.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)