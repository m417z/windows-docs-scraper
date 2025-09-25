# IMiniportAudioEngineNode::GetDeviceChannelMute

## Description

Gets the state of the Mute node for the audio device channel.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `ulChannel` [in]

The audio device channel.

### `pbMute` [out]

The current state of the Mute node for the audio device channel.

## Return value

**GetDeviceChannelMute** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)