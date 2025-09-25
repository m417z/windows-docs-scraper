# NdisMoveMemory macro

## Description

The **NdisMoveMemory** function copies a specified number of bytes from one caller-supplied location to another.

## Parameters

### `Destination` [out]

A pointer to a system-space buffer that is the destination of the move. This buffer must be at
least **Length** bytes in size.

### `Source` [in]

A pointer to a system-space buffer from which this function copies the data to the destination buffer. This buffer must be at least **Length** bytes in size.

### `Length` [in]

The number of bytes to copy.

## Remarks

Both **Source** and Destination are virtual addresses.

If either address falls within a range of device memory that was mapped with [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace), a miniport driver should call one of the **Ndis..MappedMemory** functions instead of **NdisMoveMemory**.

The range specified by **Source** and **Length** cannot overlap the **Destination** range.

Callers of **NdisMoveMemory** can run at any IRQL if the given **Source** and **Destination** are resident. Otherwise, callers must be running at IRQL < DISPATCH_LEVEL, as, for example if either address is on the stack.

## See also

[**NdisAllocateMemoryWithTagPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)