# IMiniportStreamAudioEngineNode::SetStreamChannelMute

## Description

Sets the state of the Mute node in the path of the audio stream.

## Parameters

### `ulChannel` [in]

The channel for the audio stream.

### `bMute` [in]

The state to which the Mute node will be set.

## Return value

**SetStreamChannelMute** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)