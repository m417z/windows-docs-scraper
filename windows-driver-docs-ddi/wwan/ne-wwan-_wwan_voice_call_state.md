# _WWAN_VOICE_CALL_STATE enumeration

## Description

The WWAN_VOICE_CALL_STATE enumeration lists the different voice call states that are supported by the
MB device.

## Constants

### `WwanVoiceCallStateNone`

The device does not support voice calls, or there is no voice call currently in progress.

### `WwanVoiceCallStateInProgress`

A voice call is currently in progress. This value applies only to devices whose voice class is
**WwanVoiceClassSeparateVoiceData**.

### `WwanVoiceCallStateHangUp`

A voice call is completed. This value applies only to devices whose voice class is
**WwanVoiceClassSeparateVoiceData**.

### `WwanVoiceCallStateMaximum`

The total number of supported voice call states.

## See also

[WWAN_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_state)