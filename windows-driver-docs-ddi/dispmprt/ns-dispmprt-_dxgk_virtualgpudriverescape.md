# _DXGK_VIRTUALGPUDRIVERESCAPE structure

## Description

Information to be passed between a user mode emulation DLL and the kernel mode driver.

## Members

### `PartitionId`

Identifies the vGPU partition if needed.

### `InputBufferSize`

The size in bytes of the buffer, *pInputBuffer* points to.

### `OutputBufferSize`

The size in bytes of the buffer, *pOutputBuffe*r points to.

### `pInputBuffer`

Pointer to the input buffer. This is the pointer to the GPUP_DRIVER_ESCAPE_INPUT, which is followed by the driver data.

### `pOutputBuffer`

Pointer to the output buffer.

## Remarks

The pointers to the input and output buffers cannot be the same.

## See also