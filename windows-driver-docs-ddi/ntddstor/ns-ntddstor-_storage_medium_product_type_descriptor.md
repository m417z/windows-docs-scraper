# _STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR structure

## Description

Used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to describe the product type of a storage device.

## Members

### `Version`

Contains the size of this structure, in bytes, as defined by `Sizeof(STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR)`. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `MediumProductType`

Specifies the product type of the storage device.

| **MediumProductType** value | Description |
| --- | --- |
| `00h` | Not indicated |
| `01h` | CFast |
| `02h` | CompactFlash |
| `03h` | Memory Stick |
| `04h` | MultiMediaCard |
| `05h` | Secure Digital Card (SD Card) |
| `06h` | QXD |
| `07h` | Universal Flash Storage |
| `08h` to `EFh` | Reserved |
| `F0h` to `FFh` | Vendor-specific |

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)