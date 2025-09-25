# NdisInterlockedDecrement macro

## Description

The
**NdisInterlockedDecrement** function decrements a caller-supplied variable of type LONG as an atomic
operation.

## Parameters

### `Addend` [in]

A pointer to the variable to be decremented.

## Return value

**NdisInterlockedDecrement** returns the decremented value.

## Remarks

**NdisInterlockedDecrement** can safely be used on variables in pageable memory.

**NdisInterlockedDecrement** is atomic only with respect to other
**NdisInterlocked*Xxx*** calls.

This macro is a wrapper around the [**InterlockedDecrement**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement) macro.

## See also

[NdisInterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockedincrement)