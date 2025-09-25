# GetDebuggerData macro

## Description

The **GetDebuggerData** function retrieves information stored in a data block.

## Parameters

### `TAG`

This should be set equal to KDBG_TAG. (This value is specified in wdbgexts.h.)

### `BUF`

Points to the debugger data block.

### `SIZE`

Specifies the size of the data block, including the header.

## Remarks

### Returns

If the data block is found, the return value is TRUE; otherwise, it is FALSE.