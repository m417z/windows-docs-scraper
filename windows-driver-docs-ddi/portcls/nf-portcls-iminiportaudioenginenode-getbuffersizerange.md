# IMiniportAudioEngineNode::GetBufferSizeRange

## Description

Gets the minimum and maximum buffer size that the hardware audio engine can support.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `pKsDataFormatWfx` [in]

A [KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex) structure that represents the audio data format for the audio device.

### `pBufferSizeRange` [out]

A [KSAUDIOENGINE_BUFFER_SIZE_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_tagksaudioengine_buffer_size_range) structure that represents the minimum and maximum buffer size that the hardware audio engine can support at the time when it is called.

## Return value

**GetBufferSizeRange** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)