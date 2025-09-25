# RtlCmEncodeMemIoResource function

## Description

The **RtlCmEncodeMemIoResource** routine updates a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure to describe a range of memory or I/O port addresses.

## Parameters

### `Descriptor` [in]

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure to update.

### `Type` [in]

The resource type of the memory. This parameter can be **CmResourceTypeMemory**, **CmResourceTypeMemoryLarge**, or **CmResourceTypePort**.

### `Length` [in]

The length, in bytes, of the range of allocated addresses.

### `Start` [in]

The starting address of the range of memory or I/O port addresses.

## Return value

**RtlCmEncodeMemIoResource** returns an NTSTATUS value. This routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure has been updated. |
| **STATUS_UNSUCCESSFUL** | The specified value for *Length* cannot be encoded in a **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure. |
| **STATUS_INVALID_PARAMETER** | One or more of the specified parameters are invalid. |

## Remarks

Addresses that are larger than 32 bits in length must satisfy certain alignment restrictions or else the routine returns STATUS_UNSUCCESSFUL.

| Address length | Alignment restriction |
| --- | --- |
| 40 bits | Lowest 8 bits must be zero. |
| 48 bits | Lowest 16 bits must be zero. |
| 64 bits | Lowest 32 bits must be zero. |

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource)