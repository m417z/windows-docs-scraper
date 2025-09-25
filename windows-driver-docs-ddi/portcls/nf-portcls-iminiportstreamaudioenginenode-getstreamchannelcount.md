# IMiniportStreamAudioEngineNode::GetStreamChannelCount

## Description

Gets a count of the number of channels available for the stream.

## Parameters

### `targetType` [in]

An [eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype) enumerated value that specifies the target node type.

### `pulChannelCount` [out]

The number of available channels.

## Return value

**GetStreamChannelCount** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)

[eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype)