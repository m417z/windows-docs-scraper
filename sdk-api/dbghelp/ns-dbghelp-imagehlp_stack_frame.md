# IMAGEHLP_STACK_FRAME structure

## Description

Contains the stack frame information. This structure is used with the
[SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext) function.

## Members

### `InstructionOffset`

The program counter.

**x86:** The program counter is EIP.

**Intel Itanium:** The program counter is a combination of the bundle address and a slot indicator of 0, 4, or 8 for the slot within the bundle.

**x64:** The program counter is RIP.

### `ReturnOffset`

The return address.

### `FrameOffset`

The frame pointer.

**x86:** The frame pointer is EBP.

**Intel Itanium:** There is no frame pointer, but **AddrBStore** is used.

**x64:** The frame pointer is RBP. AMD-64 does not always use this value.

### `StackOffset`

The stack pointer.

**x86:** The stack pointer is ESP.

**Intel Itanium:** The stack pointer is SP.

**x64:** The stack pointer is RSP.

### `BackingStoreOffset`

**Intel Itanium:** The backing store address.

### `FuncTableEntry`

**x86:** An
[FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data) structure. If there is no function table entry, this member is **NULL**.

### `Params`

The possible arguments to the function.

### `Reserved`

This member is reserved for system use.

### `Virtual`

If this is a virtual frame, this member is **TRUE**. Otherwise, this member is **FALSE**.

### `Reserved2`

This member is reserved for system use.

## See also

[SymSetContext](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetcontext)