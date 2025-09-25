# IAudioEndpointOffloadStreamVolume::GetChannelVolumes

## Description

The **GetChannelVolumes** method retrieves the volume levels for the various audio channels in the offloaded stream.

## Parameters

### `u32ChannelCount` [in]

Indicates the number of available audio channels in the offloaded stream.

### `pf32Volumes` [out]

A pointer to the volume levels for the various audio channels in the offloaded stream.

## Return value

The **GetChannelVolumes** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioEndpointOffloadStreamVolume](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointoffloadstreamvolume)