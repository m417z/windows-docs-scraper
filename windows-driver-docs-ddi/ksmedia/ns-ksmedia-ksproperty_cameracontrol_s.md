## Description

The **KSPROPERTY_CAMERACONTROL_S** structure describes filter-based properties in the [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol) property set.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Value`

Specifies the value of the property. This member is read/write.

### `Flags`

Indicates, for Get requests, the current setting for the specified property from the values listed below. Indicates, for Set requests, the desired setting for the specified property from the values listed below. This member can be set to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL | Indicates that the setting is controlled manually. |
| KSPROPERTY_CAMERACONTROL_FLAGS_AUTO | Indicates that the setting is controlled automatically. |
| KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE | Indicates that the setting is in absolute values. |
| KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE | Indicates that the setting is in relative values. |

### `Capabilities`

Indicates the minidriver's camera control capabilities for the specified property. This member is read-only. This member can be set to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL | Indicates that the device can be controlled manually. |
| KSPROPERTY_CAMERACONTROL_FLAGS_AUTO | Indicates that the device can be controlled automatically. |
| KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE | Indicates that the device settings are in absolute values. |
| KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE | Indicates that the device settings are in relative values. |

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[**KSPROPERTY_CAMERACONTROL_NODE_S**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_cameracontrol_node_s)

[PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol)