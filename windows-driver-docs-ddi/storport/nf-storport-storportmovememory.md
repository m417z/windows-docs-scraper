# StorPortMoveMemory function

## Description

The **StorPortMoveMemory** routine copies memory from one buffer to another.

## Parameters

### `WriteBuffer` [in]

Pointer to the destination buffer.

### `ReadBuffer` [in]

Pointer to the source buffer.

### `Length` [in]

Specifies how many bytes to transfer from *ReadBuffer* to *WriteBuffer*.

## Return value

None

## See also

[ScsiPortMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportmovememory)