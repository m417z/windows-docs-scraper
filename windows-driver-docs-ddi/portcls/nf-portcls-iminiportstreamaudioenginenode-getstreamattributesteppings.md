# IMiniportStreamAudioEngineNode::GetStreamAttributeSteppings

## Description

Gets the allowed stepping value for the audio stream attribute.

## Parameters

### `targetType` [in]

An [eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype) enumerated value that specifies the target node type.

### `pKsPropStepLong` [out]

A structure of type [KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_stepping_long) that contains information about the allowed stepping value for the audio stream attribute.

### `ui32DataSize` [in]

The allowed stepping value.

## Return value

**GetStreamAttributeSteppings** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error

code.

## See also

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)

[KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_stepping_long)

[eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype)