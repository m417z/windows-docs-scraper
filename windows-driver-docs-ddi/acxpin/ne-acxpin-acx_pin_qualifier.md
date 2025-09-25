## Description

The **ACX_PIN_QUALIFIER** enumeration specify how the PIN is connected in the multi-circuit audio topology.

## Constants

### `AcxPinQualifierUnknown`

Indicates that the pin qualifier is unknown.

### `AcxPinQualifierBridgeA`

Indicates composite support only. This pin is a bridge to another circuit on the streaming pin direction. This pin binds with AcxPinQualifierBridgeB pin type.

### `AcxPinQualifierBridgeB`

Indicates composite support only. This pin is a bridge to another circuit on the device pin direction. This pin binds with AcxPinQualifierBridgeA pin type.

### `AcxPinQualifierBridgeDevice`

Indicates composite support only.

### `AcxPinQualifierMaximum`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)