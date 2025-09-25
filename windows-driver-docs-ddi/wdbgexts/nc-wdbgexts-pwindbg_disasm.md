# PWINDBG_DISASM callback function

## Description

The **PWINDBG_DISASM** (**Disasm**) function disassembles the instruction pointed to by *lpOffset* and places the printable string into *lpBuffer*.

## Parameters

### `lpOffset`

Points to the instruction to be disassembled.

### `lpBuffer`

Receives the disassembled instruction. This buffer must be at least 2000 characters in length.

### `fShowEffectiveAddress`

Specifies whether or not to print the effective address.

## Return value

If the routine succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.