# IMiniportStreamAudioEngineNode::GetStreamChannelPeakMeter

## Description

Gets the value of the PeakMeter node in the path of the audio stream.

## Parameters

### `ulChannel` [in]

The channel of the audio stream.

### `plPeakMeter` [out]

The PeakMeter value.

## Return value

**GetStreamChannelPeakMeter** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)