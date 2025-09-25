# KeFlushIoBuffers function

## Description

The **KeFlushIoBuffers** routine flushes the memory region described by an MDL from caches of all processors.

## Parameters

### `Mdl` [in]

A pointer to an MDL that describes the range for the I/O buffer.

### `ReadOperation` [in]

Specifies **TRUE** if the flush is being performed for a read operation, and **FALSE** for a write operation. For more information, see the following Remarks section.

### `DmaOperation` [in]

Specifies **TRUE** for a DMA transfer, **FALSE** for PIO.

## Remarks

Drivers call **KeFlushIoBuffers** to maintain data integrity during DMA or PIO device transfer operations. Calling this routine affects all processors in the machine.

If *ReadOperation* is **TRUE**, the driver is reading information from the device to system memory, so valid data still might be in the processor instruction and data caches. **KeFlushIoBuffers** flushes data from all processors' caches to system memory, including the processor on which the caller is running.

If *ReadOperation* is **FALSE**, the driver is writing data from system memory to a device, so valid data might be in the processor's data cache but not yet transferred to the device. **KeFlushIoBuffers** flushes all processors' data caches, including that of the processor on which the caller is running.

As a general rule, drivers should call **KeFlushIoBuffers** just before beginning a DMA transfer operation or immediately following any PIO read operation.

**KeFlushIoBuffers** flushes only the memory region that is described by the MDL that the *Mdl* parameter points to. To flush all the memory regions that are described by an MDL chain requires a separate **KeFlushIoBuffers** call for each MDL in the chain.

For more information, see the following topics:

[Flushing Cached Data during DMA Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/flushing-cached-data-during-dma-operations)
[Flushing Cached Data during PIO Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/flushing-cached-data-during-pio-operations)

## See also

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)