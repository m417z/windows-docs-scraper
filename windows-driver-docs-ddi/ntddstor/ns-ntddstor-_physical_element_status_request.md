# _PHYSICAL_ELEMENT_STATUS_REQUEST structure

## Description

The **PHYSICAL_ELEMENT_STATUS_REQUEST** structure defines the starting element to look for the physical element status of a device.

## Members

### `Version`

Specifies the version of this structure.

### `Size`

Specifies the size of this structure, in bytes.

### `StartingElement`

Specifies the element identifier of the first physical element addressed by this command.

### `Filter`

Restricts the physical element status descriptors to return based on the following values:

| Value | Meaning |
| --- | --- |
| 0 | All physical status descriptors are specified by the other fields in the CDB. |
| 1 | Only physical element status descriptors for which the value of **PhysicalElementHealth** in [**PHYSICAL_ELEMENT_STATUS_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_descriptor) is either:

* Greater than or equal to 0x65 and less than or equal to 0xCF.
* Equal to 0xFF.

|

### `ReportType`

Specifies the type of physical element status descriptors to return as defined in the following table:

| Value | Meaning |
| --- | --- |
| 0x0 | Return descriptors for physical elements, based on the value of **Filter**. |
| 0x1 | Return descriptors for storage elements, based on the value of **Filter**. |

### `Reserved`

Reserved for future use.

## Remarks

This structure is an input buffer for [**IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_physical_element_status).

## See also

[**IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_physical_element_status)

[**PHYSICAL_ELEMENT_STATUS_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_descriptor)