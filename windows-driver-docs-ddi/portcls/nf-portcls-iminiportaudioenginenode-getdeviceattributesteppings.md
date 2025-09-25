# IMiniportAudioEngineNode::GetDeviceAttributeSteppings

## Description

Gets the allowed stepping value for the audio device attribute.

## Parameters

### `ulNodeId` [in]

The ID for the node that represents the audio device.

### `targetType` [in]

An [eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype) enumerated value that specifies the type of target node. For example, a Volume or a Mute node.

### `pKsPropStepLong` [out]

A structure of type [KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_stepping_long) that contains information about the allowed stepping value for the device attribute.

### `ui32DataSize` [in]

The allowed stepping value.

## Return value

**GetDeviceAttributeSteppings** returns S_OK, if the call was successful. Otherwise, the method

returns an appropriate error code.

## See also

[IMiniportAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportaudioenginenode)

[KSPROPERTY_STEPPING_LONG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_stepping_long)

[eChannelTargetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-echanneltargettype)