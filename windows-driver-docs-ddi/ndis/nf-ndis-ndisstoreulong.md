# NdisStoreUlong macro

## Description

The
**NdisStoreUlong** function stores a ULONG value at a particular address, avoiding alignment
faults.

## Parameters

### `Destination`

A pointer to a location in which to store a given ULONG value.

### `Value` [in]

The value to be stored.

## Remarks

Callers of
**NdisStoreUlong** can be running at any IRQL if
*DestinationAddress* points to nonpaged pool. Otherwise, the caller must be running at IRQL <
DISPATCH_LEVEL.

## See also

[NdisRetrieveUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretrieveulong)