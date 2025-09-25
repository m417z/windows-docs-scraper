# IAudioStreamVolume::GetChannelCount

## Description

The **GetChannelCount** method retrieves the number of channels in the audio stream.

## Parameters

### `pdwCount` [out]

Pointer to a **UINT32** variable into which the method writes the channel count.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pdwCount* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

Call this method to get the number of channels in the audio stream before calling any of the other methods in the [IAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume) interface.

## See also

[IAudioStreamVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)