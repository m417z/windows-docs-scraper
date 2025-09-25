# IMiniportAudioEngineNode::GetAudioEngineDescriptor

## Description

Gets the descriptor for the audio engine node.

## Parameters

### `ulNodeId` [in]

The ID of the audio engine node.

### `pAudioEngineDescriptor` [out]

Audio engine descriptor object. This parameter is of type [KSAUDIOENGINE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_tagksaudioengine_descriptor).

## Return value

**GetAudioEngineDescriptor** returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[KSAUDIOENGINE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_tagksaudioengine_descriptor)