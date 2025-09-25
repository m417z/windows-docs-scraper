# ReadListEntry function

## Description

The **ReadListEntry** function reads a doubly-linked list entry from the target's memory.

## Parameters

### `Address`

Specifies the address of the list entry in the target. If the target uses 32-bit pointers, this should be the address of a LIST_ENTRY32 structure. If the target uses 64-bit pointers, this should be the address of a LIST_ENTRY64 structure.

### `List`

Receives a LIST_ENTRY64 structure that contains pointers to the previous and next entries in the list. If the target uses 32-bit pointers, they are sign-extended to 64 bits.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

For more information about the LIST_ENTRY structures, see the Windows Driver Kit (WDK) documentation.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

LIST_ENTRY64 and LIST_ENTRY32 are defined in **winnt.h**.