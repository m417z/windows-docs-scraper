# IMiniportAudioEngineNode::GetDeviceChannelCount

## Description

Gets a count of the number of channels supported by the audio device.

## Parameters

### `ulNodeId` [in]

The ID of the node that represents the audio device.

### `targetType` [in]

An [eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype) enumerated value that specifies the types of target nodes in the channels. For example, there could be Volume, Mute or PeakMeter nodes.

### `pulChannelCount` [out]

The number of channels supported by the audio device.

## Return value

**GetDeviceChannelCount** returns S_OK, if the call was successful. Otherwise, the method

returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype)