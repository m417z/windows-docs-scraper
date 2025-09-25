# ReadPointer function

## Description

The **ReadPointer** function reads a pointer from the target.

## Parameters

### `Address`

Specifies the address of the pointer to read.

### `Pointer`

Receives the value of the pointer. If the target uses 32-bit pointers, the pointer is sign-extended to 64 bits.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

## See also

[WritePointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writepointer)