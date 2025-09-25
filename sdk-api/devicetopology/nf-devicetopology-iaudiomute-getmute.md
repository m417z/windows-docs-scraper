# IAudioMute::GetMute

## Description

The **GetMute** method gets the current state (enabled or disabled) of the mute control.

## Parameters

### `pbMuted` [out]

Pointer to a **BOOL** variable into which the method writes the current state of the mute control. If the state is **TRUE**, muting is enabled. If **FALSE**, it is disabled.

## Return value

| Return code | Description |
| --- | --- |
| E_POINTER | Pointer *pbMuted* is **NULL**. |

## See also

[IAudioMute Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomute)