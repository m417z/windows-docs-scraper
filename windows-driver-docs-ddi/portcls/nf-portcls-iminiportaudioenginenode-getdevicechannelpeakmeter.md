# IMiniportAudioEngineNode::GetDeviceChannelPeakMeter

## Description

Gets the PeakMeter value for the audio device channel.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `ulChannel` [in]

The audio device channel.

### `plPeakMeter` [out]

The PeakMeter value for the audio device channel.

## Return value

**GetDeviceChannelPeakMeter** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)