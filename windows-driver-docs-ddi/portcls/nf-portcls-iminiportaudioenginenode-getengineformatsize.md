# IMiniportAudioEngineNode::GetEngineFormatSize

## Description

Gets the format type and the buffer size for the audio engine's audio data format.

## Parameters

### `ulNodeId` [in]

The ID of the audio engine node.

### `formatType` [in]

An enum of type [eEngineFormatType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-eengineformattype) that represents the audio data format type.

### `pulFormatSize` [out]

The data buffer size for the format type.

## Return value

**GetEngineFormatSize** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[eEngineFormatType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-eengineformattype)