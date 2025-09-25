# SYSAUDIO_CREATE_VIRTUAL_SOURCE structure

## Description

The SYSAUDIO_CREATE_VIRTUAL_SOURCE structure is used to create a mixer-line virtual source such as a volume control or mute.

## Members

### `Property`

Specifies the property. This parameter is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `PinCategory`

Specifies a category for the created pin. This parameter is a KSCATEGORY_*Xxx* GUID.

### `PinName`

Specifies a name for the created pin. If the *PinCategory* parameter uniquely identifies the pin to create, set *PinName* to the same GUID as *PinCategory*. Otherwise, set *PinName* to a pin-name GUID that uniquely distinguishes the target pin from other pins of type KSCATEGORY_*Xxx*.

## Remarks

This structure is used by the [KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-create-virtual-source) property.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-create-virtual-source)