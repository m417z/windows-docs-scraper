# _D3DKMT_SUBMITCOMMAND structure

## Description

The **D3DKMT_SUBMITCOMMAND** structure is used to submit command buffers on contexts that support graphics processing unit (GPU) virtual addressing.

## Members

### `Commands`

The GPU virtual address for the commands being submitted to the context for execution. This information is provided to the driver during command submission and is also used for debugging purposes.

### `CommandLength`

Specifies the length, in bytes, of the commands being submitted to the GPU.

### `Flags`

An instance of the [D3DDDICB_SUBMITCOMMANDFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommandflags) structure.

### `PresentHistoryToken`

This member is reserved for future use.

### `BroadcastContextCount`

Specifies the number of context these command should be submitted to. This count must be at least 1.

### `BroadcastContext`

Specifies the handle of the context to execute the specified commands.

### `pPrivateDriverData`

Pointer to the driver private data to submitted by the user mode driver.

### `PrivateDriverDataSize`

Size of the private driver data information being passed. This size must be smaller than the size requested by the kernel mode driver for submission private driver data or the call will fail.

### `NumPrimaries`

Specifies the number of primaries and swapchain back buffers being written to by the submitted commands. This is equal to the number of allocations in the **WrittenPrimaries** array.

### `WrittenPrimaries`

Arrays of handle to the primaries and swapchain back buffers being written to by the submitted commands.

### `NumHistoryBuffers`

This member is reserved for future use.

### `HistoryBufferArray`

This member is reserved for future use.

## See also

[D3DDDICB_SUBMITCOMMANDFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommandflags)