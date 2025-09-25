# NdisRetrieveUlong macro

## Description

The
**NdisRetrieveUlong** function retrieves a ULONG value from the source address, avoiding alignment
faults.

## Parameters

### `Destination`

A pointer to a ULONG-aligned memory location in which to store the value.

### `Source`

A pointer to a memory location from which to retrieve the ULONG value.

## Remarks

The given
*DestinationAddress* is assumed to be aligned on a ULONG boundary.

Callers of
**NdisRetrieveUlong** can be running at any IRQL if the given addresses are in nonpaged pool.
Otherwise, callers must be running at IRQL < DISPATCH_LEVEL.

## See also

[NdisStoreUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstoreulong)