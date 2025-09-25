# IMiniportStreamAudioEngineNode::GetStreamChannelMute

## Description

Gets the state of the Mute node in the path of the audio stream.

## Parameters

### `ulChannel` [in]

The audio stream channel.

### `pbMute` [out]

The state of the Mute node.

## Return value

**GetStreamChannelMute** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)