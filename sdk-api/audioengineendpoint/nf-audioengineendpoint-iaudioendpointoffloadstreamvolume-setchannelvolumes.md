# IAudioEndpointOffloadStreamVolume::SetChannelVolumes

## Description

The **SetChannelVolumes** method sets the volume levels for the various audio channels in the offloaded stream.

## Parameters

### `u32ChannelCount` [in]

Indicates the number of available audio channels in the offloaded stream.

### `pf32Volumes` [in]

A pointer to the volume levels for the various audio channels in the offloaded stream.

### `u32CurveType`

A value from the [AUDIO_CURVE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ne-ksmedia-audio_curve_type) enumeration specifying the curve to use when changing the channel volumes.

### `pCurveDuration`

A **LONGLONG** value specifying the curve duration in hundred nanosecond units.

## Return value

The **SetChannelVolumes** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioEndpointOffloadStreamVolume](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointoffloadstreamvolume)