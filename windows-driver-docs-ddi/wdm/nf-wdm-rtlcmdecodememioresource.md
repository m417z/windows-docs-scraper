# RtlCmDecodeMemIoResource function

## Description

The **RtlCmDecodeMemIoResource** routine provides the starting address and length of a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes a range of memory or I/O port addresses.

## Parameters

### `Descriptor` [in]

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure to provide the starting address and length for.

### `Start` [out, optional]

A pointer to a variable that receives the starting address of the range of memory or I/O port addresses.

## Return value

**RtlCmDecodeMemIoResource** returns the length of the address range, in bytes.

## Remarks

The **Type** member of the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure must be **CmResourceTypeMemory**, **CmResourceTypeMemoryLarge**, or **CmResourceTypePort**.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource)