# IAudioEndpointVolume::GetMasterVolumeLevel

## Description

The **GetMasterVolumeLevel** method gets the master volume level, in decibels, of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `pfLevelDB` [out]

Pointer to the master volume level. This parameter points to a **float** variable into which the method writes the volume level in decibels. To get the range of volume levels obtained from this method, call the [IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange) method.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfLevelDB* is **NULL**. |

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange)