# IMiniportStreamAudioEngineNode::GetStreamLinearBufferPosition

## Description

 Gets the number of bytes that the DMA has fetched from the audio buffer since the beginning of the stream.

## Parameters

### `pullLinearBufferPosition` [out]

The number of bytes that the DMA has fetched.

## Return value

**GetStreamLinearBufferPosition** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)