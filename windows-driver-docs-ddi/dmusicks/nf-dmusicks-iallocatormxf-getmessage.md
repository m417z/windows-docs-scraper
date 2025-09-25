# IAllocatorMXF::GetMessage

## Description

The `GetMessage` method serves as the retrieval point for any DirectMusic kernel-mode component that utilizes the port driver's allocator to reuse [DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event) structures.

## Parameters

### `ppDMKEvt` [out]

Output pointer for the MIDI event. This parameter points to a caller-allocated pointer variable into which the method writes a pointer to the event structure being retrieved from the allocator. The structure itself is empty (zeroed by the allocator).

## Return value

`GetMessage` returns S_OK if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

The miniport driver uses the `GetMessage` method to retrieve event structures for MIDI rendering and capture. This method retrieves [DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event) structures from the same pool that [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage) puts them into when it discards them to the allocator.

In the case of a MIDI capture stream, the port driver retrieves capture events from the miniport driver when prompted by the usual Service DPC.

For more information about the allocator, see [Allocator](https://learn.microsoft.com/windows-hardware/drivers/audio/allocator).

## See also

[DMUS_KERNEL_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/ns-dmusicks-_dmus_kernel_event)

[IAllocatorMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iallocatormxf)

[IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage)