## Description

The **RtlRetrieveUlong** macro retrieves a ULONG value from the source address, avoiding alignment faults. The destination address is assumed to be aligned.

## Parameters

### `DEST_ADDRESS` [out]

Pointer to a ULONG-aligned location in which to store the ULONG value.

### `SRC_ADDRESS` [in]

Pointer to a location from which to retrieve the ULONG value.

## Remarks

Callers of **RtlRetrieveUlong** can be running at any IRQL if the given addresses are in nonpaged pool. Otherwise, the caller must be running at IRQL <= APC_LEVEL.