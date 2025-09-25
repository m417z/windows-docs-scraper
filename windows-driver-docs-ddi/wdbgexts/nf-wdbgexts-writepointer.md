# WritePointer function

## Description

The **WritePointer** function writes a pointer to the target.

## Parameters

### `Address`

Specifies the address to write the pointer to.

### `Pointer`

Specifies the value of the pointer. If the target uses 32-bit pointers, *Pointer* is a 32-bit value that has been sign-extended to 64-bits.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.

## See also

[ReadPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readpointer)