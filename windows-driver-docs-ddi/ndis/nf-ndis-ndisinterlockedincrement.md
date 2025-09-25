# NdisInterlockedIncrement macro

## Description

The
**NdisInterlockedIncrement** function increments a caller-supplied variable as an atomic
operation.

## Parameters

### `Addend` [in]

A pointer to a variable of type LONG.

## Remarks

**NdisInterlockedIncrement** cannot be used on variables in pageable memory.

**NdisInterlockedIncrement** is atomic only with respect to other
**NdisInterlocked*Xxx*** calls.

## See also

[NdisInterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinterlockeddecrement)