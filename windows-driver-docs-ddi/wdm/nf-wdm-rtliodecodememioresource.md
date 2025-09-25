# RtlIoDecodeMemIoResource function

## Description

The **RtlIoDecodeMemIoResource** routine provides the address information that is contained in an [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure that describes a range of memory or I/O port addresses.

## Parameters

### `Descriptor` [in]

A pointer to the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure to provide the address information for.

### `Alignment` [out, optional]

A pointer to a variable that receives the alignment, in bytes, of the address range. This parameter can be **NULL**.

### `MinimumAddress` [out, optional]

A pointer to a variable that receives the minimum address of the address range. This parameter can be **NULL**.

### `MaximumAddress` [out, optional]

A pointer to a variable that receives the maximum address of the address range. This parameter can be **NULL**.

## Return value

**RtlIoDecodeMemIoResource** returns the length of the address range, in bytes.

## Remarks

The **Type** member of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure must be **CmResourceTypeMemory**, **CmResourceTypeMemoryLarge**, or **CmResourceTypePort**.

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[RtlIoEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlioencodememioresource)