# ITPhone::put_HookSwitchState

## Description

The
**put_HookSwitchState** method sets the current hookswitch state for a particular hookswitch device on the phone.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `HookSwitchDevice` [in]

The
[PHONE_HOOK_SWITCH_DEVICE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_device) descriptor for the hookswitch type.

### `HookSwitchState` [in]

The
[PHONE_HOOK_SWITCH_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_hook_switch_state) descriptor for the hookswitch status.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Typically, speakerphones and headsets have application-settable hookswitch states, and handsets do not, but this feature is TSP-dependent.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_HookSwitchState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_hookswitchstate)