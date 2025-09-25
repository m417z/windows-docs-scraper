# IMiniportAudioEngineNode::SetDeviceChannelVolume

## Description

Sets the volume level for a given channel of the audio device.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `ulChannel` [in]

The audio device channel.

### `lVolume` [in]

The volume level to which the channel will be set.

## Return value

**SetDeviceChannelVolume** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)