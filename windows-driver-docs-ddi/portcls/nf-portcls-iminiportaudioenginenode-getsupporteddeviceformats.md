# IMiniportAudioEngineNode::GetSupportedDeviceFormats

## Description

Gets the supported audio data formats for the audio device.

## Parameters

### `ulNodeId` [in]

The ID of the node that represents the audio device.

### `pFormats` [out]

A structure of type [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) that points to the array of audio data formats supported by the audio device.

### `ulBufferSize` [in]

The buffer size for the audio data format information.

## Return value

**GetSupportedDeviceFormats** returns S_OK, if the call was successful. Otherwise, the method

returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)