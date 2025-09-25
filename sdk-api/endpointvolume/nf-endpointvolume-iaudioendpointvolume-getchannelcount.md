# IAudioEndpointVolume::GetChannelCount

## Description

The **GetChannelCount** method gets a count of the channels in the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `pnChannelCount` [out]

Pointer to a **UINT** variable into which the method writes the channel count.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pnChannelCount* is **NULL**. |

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)