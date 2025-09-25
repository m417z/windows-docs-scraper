## Description

The **RtlStoreUshort** macro stores a USHORT value at a particular address, avoiding alignment faults.

## Parameters

### `ADDRESS` [out]

A pointer to a location in which to store the specified USHORT value.

### `VALUE` [in]

Specifies a USHORT value to be stored.

## Remarks

The caller can be running at any IRQL if _Address_ points to nonpaged pool. Otherwise, the caller must be running at IRQL <= APC_LEVEL.