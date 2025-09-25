# IAllocatorMXF::PutBuffer

## Description

 This method is not currently used by the miniport driver. The `PutBuffer` method passes a buffer to the allocator, but this occurs automatically when [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage) is called anyway.

## Parameters

### `pBuffer` [in]

Pointer to the buffer being passed to the allocator

## Return value

`PutBuffer` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport driver does not need to use this method because when the miniport driver calls [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage), the allocator looks at the **cbEvent** member of the [DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event) structure to determine if **uData** is a pointer or just data. If **cbEvent** specifies that the event data is greater than the storage capacity of **uData** (4 bytes on a 32-bit system and 8 bytes on a 64-bit system), the allocator simply assumes that **uData** points to a buffer that can be reused.

## See also

[DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event)

[IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf)

[IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage)