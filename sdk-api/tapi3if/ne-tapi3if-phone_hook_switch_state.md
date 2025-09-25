# PHONE_HOOK_SWITCH_STATE enumeration

## Description

The
**PHONE_HOOK_SWITCH_STATE** enum provides indicators of the phone hookswitch status.

## Constants

### `PHSS_ONHOOK:0x1`

Indicates that the phone is onhook.

### `PHSS_OFFHOOK_MIC_ONLY:0x2`

Indicates that only the phone's microphone is offhook.

### `PHSS_OFFHOOK_SPEAKER_ONLY:0x4`

Indicates that only the phone's speaker is offhook.

### `PHSS_OFFHOOK:0x8`

Indicates that the phone is offhook.

## See also

[ITPhone::get_HookSwitchState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_hookswitchstate)

[ITPhone::put_HookSwitchState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_hookswitchstate)

[ITPhoneEvent::get_HookSwitchState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_hookswitchstate)