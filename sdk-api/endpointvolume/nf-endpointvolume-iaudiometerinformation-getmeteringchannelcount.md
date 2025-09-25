# IAudioMeterInformation::GetMeteringChannelCount

## Description

The **GetMeteringChannelCount** method gets the number of channels in the audio stream that are monitored by peak meters.

## Parameters

### `pnChannelCount` [out]

Pointer to a **UINT** variable into which the method writes the number of channels.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pnChannelCount* is **NULL**. |

## See also

[IAudioMeterInformation Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudiometerinformation)