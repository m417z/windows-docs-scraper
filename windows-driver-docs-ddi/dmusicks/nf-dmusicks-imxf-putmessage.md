# IMXF::PutMessage

## Description

The PutMessage method passes a DMUS_KERNEL_EVENT structure to its next destination. The miniport driver uses this method to discard used event structures so that they can be recycled by the allocator.

Syntax

## Parameters

### `pDMKEvt`

Pointer to the DMUS_KERNEL_EVENT structure being passed to its destination.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

During rendering, the miniport driver calls the PutMessage method to discard used DMUS_KERNEL_EVENT structures. The method routes the discarded structures to the allocator for reuse. The miniport driver calls this method once it has extracted the MIDI data from the structures for rendering.

During MIDI capture, this method is used to package and pass MIDI messages to the DMus port driver's capture sink, as shown in the figure in MIDI Transport. These messages can be single, multiple, or fragmentary MIDI events and are packaged in DMUS_KERNEL_EVENT structures (which are retrieved by IAllocatorMXF::GetMessage calls).

The allocator is always the last destination in any chain, so every DMUS_KERNEL_EVENT structure will eventually be recycled. If IMXF::ConnectOutput has not been called, PutMessage will default to passing the structure to the allocator. For more information, see Allocator.

## See also

[IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf)