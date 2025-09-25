# _PHYSICAL_ELEMENT_STATUS_DESCRIPTOR structure

## Description

The **PHYSICAL_ELEMENT_STATUS_DESCRIPTOR** structure contains status information for a physical element.

## Members

### `Version`

Specifies the version of this structure.

### `Size`

Specifies the size of this structure, in bytes.

### `ElementIdentifier`

Specifies the identifier of the physical element associated with this Physical Element Status descriptor.

### `PhysicalElementType`

Indicates the type of the physical element associated with this Physical Element Status descriptor, as described in the following table.

| Value | Meaning |
| --- | --- |
| 0x01 | Storage Element |

### `PhysicalElementHealth`

Indicates the health of the physical element associated with this Physical Element Status descriptor, as described in the following table.

| Value | Meaning |
| --- | --- |
| 0x00 | Not reported. |
| 0x01 to 0x63 | Within manufacturer’s specification limits. |
| 0x64 | At manufacturer’s specification limit. |
| 0x65 to 0xCF | Outside manufacturer’s specification limit. |
| 0xD0 to 0xFE | Reserved. |
| 0xFF | Depopulated. |

### `Reserved1`

Reserved for future use.

### `AssociatedCapacity`

Indicates the number of logical blocks by which the capacity of the device is reduced if the physical element associated with this Physical Element Status descriptor becomes depopulated.

### `Reserved2`

Reserved for future use.

## Remarks

## See also

[**PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status)