# IMiniportStreamAudioEngineNode::SetStreamChannelVolume

## Description

Sets the volume level to be applied to the audio stream.

## Parameters

### `Channel` [in]

The audio stream channel.

### `TargetVolume` [in]

The volume level to be applied to the audio stream.

### `CurveType` [in]

The curve algorithm that will be used to set the volume level. The curve types are represented by the members of the [AUDIO_CURVE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type) enum.

### `CurveDuration` [in]

The length of time over which the curve algorithm will be applied.

## Return value

**SetStreamChannelVolume** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)