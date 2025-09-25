## Description

The **KSPROPERTY_CAMERACONTROL_S2** structure describes filter-based properties in the [PROPSETID_VIDCAP_CAMERACONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-cameracontrol) property set that use two values at the same time.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Value1`

Specifies the first value of the property. This member is read/write.

### `Flags`

Indicates, for get requests, the current setting for the specified property from the values listed below. Indicates, for set requests, the desired setting for the specified property from the values listed below. This member can be set to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL | Indicates that the setting is controlled manually |
| KSPROPERTY_CAMERACONTROL_FLAGS_AUTO | Indicates that the setting is controlled automatically |
| KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE | Indicates that the setting is in absolute values |
| KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE | Indicates that the setting is in relative values |

### `Capabilities`

Indicates the minidriver's camera control capabilities for the specified property. This member is read-only. This member can be set to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL | Indicates that the device can be controlled manually |
| KSPROPERTY_CAMERACONTROL_FLAGS_AUTO | Indicates that the device can be controlled automatically |
| KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE | Indicates that the device settings are in absolute values |
| KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE | Indicates that the device settings are in relative values |

### `Value2`

Specifies the second value of the property. This member is read/write.

## Remarks

This structure is used by [KSPROPERTY_CAMERACONTROL_PANTILT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-pantilt) and [KSPROPERTY_CAMERACONTROL_PANTILT_RELATIVE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-pantilt-relative) for filter-based get/set property requests.