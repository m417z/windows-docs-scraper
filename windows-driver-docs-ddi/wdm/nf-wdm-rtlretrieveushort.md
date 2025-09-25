## Description

The **RtlRetrieveUshort** macro retrieves a USHORT value from the source address, avoiding alignment faults.

## Parameters

### `DEST_ADDRESS` [out]

Pointer to a USHORT-aligned location in which to store the value.

### `SRC_ADDRESS` [in]

Pointer to a location from which to retrieve the value.

## Remarks

Callers of **RtlRetrieveUshort** can be running at any IRQL if the given addresses are in nonpaged pool. Otherwise, the caller must be running at IRQL <= APC_LEVEL.