# IMiniportAudioEngineNode::GetGfxState

## Description

Gets the state of the global effects (GFX) node in the audio engine.

## Parameters

### `ulNodeId` [in]

The ID of the GFX node.

### `pbEnable` [out]

Pointer to a **BOOL** data type.

## Return value

**GetGfxState** returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)