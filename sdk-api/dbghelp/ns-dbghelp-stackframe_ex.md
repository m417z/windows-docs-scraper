# STACKFRAME_EX structure

## Description

Represents an extended stack frame.

## Members

### `AddrPC`

An [ADDRESS64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-address64) structure that specifies the program
counter.

**x86:** The program counter is EIP.

**Intel Itanium:** The program counter is StIIP.

**x64:** The program counter is RIP.

### `AddrReturn`

An [ADDRESS64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-address64) structure that specifies
the return address.

### `AddrFrame`

An [ADDRESS64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-address64) structure that specifies
the frame pointer.

**x86:** The frame pointer is EBP.

**Intel Itanium:** There is no frame pointer, but **AddrBStore** is used.

**x64:** The frame pointer is RBP or RDI. This value is not always used.

### `AddrStack`

An [ADDRESS64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-address64) structure that specifies
the stack pointer.

**x86:** The stack pointer is ESP.

**Intel Itanium:** The stack pointer is SP.

**x64:** The stack pointer is RSP.

### `AddrBStore`

**Intel Itanium:** An [ADDRESS64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-address64) structure that specifies
the backing store (RsBSP).

### `FuncTableEntry`

On x86 computers, this member is an [FPO_DATA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-fpo_data)
structure. If there is no function table entry, this member is **NULL**.

### `Params`

The possible arguments to the function.

### `Far`

This member is **TRUE** if this is a WOW far call.

### `Virtual`

This member is **TRUE** if this is a virtual frame.

### `Reserved`

This member is used internally by the [StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk64)
function.

### `KdHelp`

A [KDHELP64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-kdhelp64) structure that specifies helper data for
walking kernel callback frames.

### `StackFrameSize`

Set to `sizeof(STACKFRAME_EX)`.

### `InlineFrameContext`

Specifies the type of the inline frame context.

| Value | Meaning |
| --- | --- |
| **INLINE_FRAME_CONTEXT_INIT**<br><br>0 | Unknown. |
| **INLINE_FRAME_CONTEXT_IGNORE**<br><br>0xffffffff | Unknown. |

## Remarks

This structure supersedes the **STACKFRAME64** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support).