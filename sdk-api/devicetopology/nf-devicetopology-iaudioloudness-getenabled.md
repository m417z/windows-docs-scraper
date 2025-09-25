# IAudioLoudness::GetEnabled

## Description

The **GetEnabled** method gets the current state (enabled or disabled) of the loudness control.

## Parameters

### `pbEnabled` [out]

Pointer to a **BOOL** variable into which the method writes the current loudness state. If the state is **TRUE**, loudness is enabled. If **FALSE**, loudness is disabled.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pbEnabled* is **NULL**. |

## See also

[IAudioLoudness Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioloudness)