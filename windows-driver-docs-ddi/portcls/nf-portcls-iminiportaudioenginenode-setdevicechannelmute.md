# IMiniportAudioEngineNode::SetDeviceChannelMute

## Description

Sets the state of the Mute node for the audio device channel.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `ulChannel` [in]

The audio device channel.

### `bMute` [in]

The state to which the Mute node for the audio device channel will be set.

## Return value

**SetDeviceChannelMute** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)