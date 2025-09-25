# IMiniportWaveRTOutputStream::GetOutputStreamPresentationPosition

## Description

Returns stream presentation information.

## Parameters

### `pPresentationPosition` [out]

 pPresentationPosition returns a [KSAUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position) structure that represents a recent presentation position in the audio data stream. For more information, see [IMiniportStreamAudioEngineNode::GetStreamPresentationPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportstreamaudioenginenode-getstreampresentationposition).

## Return value

`GetOutputStreamPresentationPosition` returns STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

## Remarks

The OS may periodically get this property from the driver to retrieve recent presentation position information from the driver in order to allow upper layers to synchronize video or other activity with the audio stream.

The value returned in the u64PositionInBlocks member of KSAUDIO_PRESENTATION_POSITION should be consistent with the packet count returned by GetPacketCount and the driver’s interpretation of the packet number passed to SetWritePacket. In other words, the first sample of packet 0 is block 0.

This does not mean that GetPacketCount and GetOutputStreamPresentationPosition, if called simultaneously, would return values that refer to the same sample. GetPacketCount returns information about the samples transferred from the WaveRT buffer to the hardware, while GetOutputStreamPresentationPosition returns information about samples presented at the output of the system. These are two different pieces of information.

## See also

[IMiniportWaveRTOutputStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertoutputstream)