# IMiniportAudioEngineNode::SetDeviceFormat

## Description

Sets the audio data format for an audio device.

## Parameters

### `ulNodeId` [in]

The ID of the node that represents the device.

### `pFormat` [in]

A structure of type [KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex) that represents the audio data format to be set for the device.

### `ulBufferSize` [in]

The audio data buffer size.

## Return value

**SetDeviceFormat** returns S_OK, if the call was successful. Otherwise, the method

returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)