# RtlIoEncodeMemIoResource function

## Description

The **RtlIoEncodeMemIoResource** routine updates an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure to describe a range of memory or I/O port addresses.

## Parameters

### `Descriptor` [in]

A pointer to the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure to update.

### `Type` [in]

The resource type of the address range. This parameter can be **CmResourceTypeMemory**, **CmResourceTypeMemoryLarge**, or **CmResourceTypePort**.

### `Length` [in]

The length, in bytes, of the range of assignable addresses.

### `Alignment` [in]

The alignment, in bytes, of the starting address of address range.

### `MinimumAddress` [in]

The minimum address that can be assigned to the device.

### `MaximumAddress` [in]

The maximum address that can be assigned to the device.

## Return value

**RtlIoEncodeMemIoResource** returns an NTSTATUS value. This routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure was updated. |
| **STATUS_UNSUCCESSFUL** | The specified value for *Length* or *Alignment* could not be encoded in an **IO_RESOURCE_DESCRIPTOR** structure. |
| **STATUS_INVALID_PARAMETER** | One or more of the specified parameters were invalid. |

## Remarks

Addresses that are larger than 32 bits in length must satisfy certain alignment restrictions, or else the routine returns STATUS_UNSUCCESSFUL.

| Address length | Alignment restriction |
| --- | --- |
| 40 bits | Lowest 8 bits must be zero. |
| 48 bits | Lowest 16 bits must be zero. |
| 64 bits | Lowest 32 bits must be zero. |

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[RtlIoDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtliodecodememioresource)