# _PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR structure

## Description

The **PHYSICAL_ELEMENT_STATUS_DATA_DESCRIPTOR** structure contains status information for a physical element.

## Members

### `Reserved1`

Reserved for future use.

### `ElementIdentifier`

Indicates the identifier of the physical element associated with this Physical Element Status descriptor.

### `Reserved2`

Reserved for future use.

### `PhysicalElementType`

Indicates the type of the physical element associated with this Physical Element Status descriptor, as described in the following table.

| Value | Meaning |
| --- | --- |
| **PHYSICAL_ELEMENT_TYPE_STORAGE_ELEMENT** 0x01 | Storage Element |

### `PhysicalElementHealth`

Indicates the health of the physical element associated with this Physical Element Status descriptor, as described in the following table.

| Value | Meaning |
| --- | --- |
| 0x00 | Not reported. |
| 0x01 to 0x63 | Within manufacturer’s specification limits. |
| 0x64 | At manufacturer’s specification limit. |
| 0x65 to 0xCF | Outside manufacturer’s specification limit. |
| 0xD0 to 0xFE | Reserved. |
| 0xFF | Successfully depopulated. |

### `AssociatedCapacity`

Indicates the number of logical blocks by which the capacity of the device is reduced if the physical element associated with this Physical Element Status descriptor becomes depopulated.

### `Reserved3`

Reserved for future use.

## Remarks

## See also

[**PHYSICAL_ELEMENT_STATUS_PARAMETER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_physical_element_status_parameter_data)