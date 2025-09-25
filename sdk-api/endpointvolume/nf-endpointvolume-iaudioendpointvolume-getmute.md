# IAudioEndpointVolume::GetMute

## Description

The **GetMute** method gets the muting state of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `pbMute` [out]

Pointer to a **BOOL** variable into which the method writes the muting state. If **pbMute* is **TRUE**, the stream is muted. If **FALSE**, the stream is not muted.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pbMute* is **NULL**. |

## Remarks

For a code example that calls **GetMute**, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)