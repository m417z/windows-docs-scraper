# IMiniportAudioEngineNode::GetDeviceChannelVolume

## Description

Gets the volume level for a given channel of the audio device.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `ulChannel` [in]

The audio device channel.

### `plVolume` [out]

The current volume level for the audio device channel.

## Return value

**GetDeviceChannelVolume** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)