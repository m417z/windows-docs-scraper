# ITPhone::get_HookSwitchState

## Description

The
**get_HookSwitchState** method retrieves the current hookswitch state for a particular hookswitch device on the phone.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `HookSwitchDevice` [in]

The
[PHONE_HOOK_SWITCH_DEVICE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_device) descriptor for the hookswitch type.

### `pHookSwitchState` [out]

The
[PHONE_HOOK_SWITCH_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_state) descriptor for the hookswitch status.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[put_HookSwitchState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_hookswitchstate)