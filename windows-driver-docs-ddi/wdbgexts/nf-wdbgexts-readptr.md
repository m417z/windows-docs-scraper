# ReadPtr function

## Description

The **ReadPtr** function reads a pointer from the target. [ReadPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readpointer) should be used instead of this function as the return value of **ReadPointer** is more consistent with the rest of the WdbgExts API.

## Parameters

### `Addr`

Specifies the address of the pointer to read.

### `pPointer`

Receives the value of the pointer. If the target uses 32-bit pointers, the pointer is sign-extended to 64 bits.

## Return value

If the function succeeds, the return value is **FALSE**; otherwise, it is **TRUE**.

## Remarks

This function is identical to [ReadPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readpointer), except the meaning of the return value is reversed.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

## See also

[ReadPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readpointer)