# IAudioAutoGainControl::GetEnabled

## Description

The **GetEnabled** method gets the current state (enabled or disabled) of the AGC.

## Parameters

### `pbEnabled` [out]

Pointer to a **BOOL** variable into which the method writes the current AGC state. If the state is **TRUE**, AGC is enabled. If **FALSE**, AGC is disabled.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pbEnabled* is **NULL**. |

## Remarks

A disabled AGC operates in pass-through mode. In this mode, the audio stream passes through the AGC without modification.

## See also

[IAudioAutoGainControl Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol)