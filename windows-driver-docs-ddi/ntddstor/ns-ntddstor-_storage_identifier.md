# _STORAGE_IDENTIFIER structure

## Description

The STORAGE_IDENTIFIER structure represents a SCSI identification descriptor.

## Members

### `CodeSet`

Specifies the code set used by a SCSI identification descriptor to identify a logical unit.

### `Type`

Contains an enumerator value of type [STORAGE_IDENTIFIER_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566990(v=vs.85)) that indicates the identifier type.

### `IdentifierSize`

Specifies the size in bytes of the identifier.

### `NextOffset`

Specifies the offset in bytes from the current descriptor to the next descriptor.

### `Association`

Contains an enumerator value of type [STORAGE_ASSOCIATION_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566349(v=vs.85)) that indicates whether the descriptor identifies a device or a port.

### `Identifier`

Contains the identifier associated with this descriptor.

## Remarks

Every device identification page (page code 0x83) of SCSI vital product data contains a series of identification descriptors. The STORAGE_IDENTIFIER structure represents a SCSI identification descriptor.

## See also

[STORAGE_ASSOCIATION_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566349(v=vs.85))

[STORAGE_IDENTIFIER_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566990(v=vs.85))