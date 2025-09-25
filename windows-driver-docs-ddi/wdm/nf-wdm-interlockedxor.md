# InterlockedXor function (wdm.h)

## Description

The **InterlockedOr** routine atomically computes a bitwise exclusive OR operation.

## Parameters

### `Destination` [in, out]

A pointer to the variable to be exclusive ORed with *Value*. The result of the operation is stored in the variable.

### `Value` [in]

Specifies the value to be exclusive ORed with the variable that is pointed to by *Destination*.

## Return value

**InterlockedXor** returns the original value stored in the variable pointed to by *Destination*.

## Remarks

**InterlockedXor** atomically computes ******Destination***^=***Value*.

Interlocked operations cannot be used on non-cached memory.

## See also

[InterlockedAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedand)

[InterlockedOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedor)