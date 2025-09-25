## Description

Kernel streaming clients use the KSP_PIN structure to specify the property and pin type within a KSPROPSETID_Pin property request.

## Members

### `Property`

Specifies a [**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure.

### `PinId`

Specifies the pin type ID.

### `Reserved`

Reserved. Should be set to zero.

Reserved. Should be set to zero.

### `Flags`

Pin flags. This is set to either 0 or the following.

| Value | Description |
|---|---|
| **KSPROPERTY_PIN_FLAGS_ATTRIBUTE_RANGE_AWARE** | The client is aware of attributes and handles attribute ranges. |

## See also

[**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)