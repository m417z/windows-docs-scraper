# InterlockedAnd function (miniport.h)

## Description

The **InterlockedAnd** macro atomically computes a bitwise AND operation.

## Parameters

### `Destination` [in, out]

A pointer to the variable to be ANDed with *Value*. The result of the operation is stored in the variable.

### `Value` [in]

Specifies the value to be ANDed with the variable that is pointed to by *Destination*.

## Return value

**InterlockedAnd** returns the original value stored in the variable pointed to by *Destination*.

## Remarks

**InterlockedAnd** atomically computes ******Destination***&=***Value*.

Interlocked operations cannot be used on non-cached memory.

## See also

[InterlockedOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedor)

[InterlockedXor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedxor)