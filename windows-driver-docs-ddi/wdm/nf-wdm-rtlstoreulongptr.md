## Description

The **RtlStoreUlongPtr** macro stores a specified ULONG_PTR value at a specified memory location, avoiding memory alignment faults.

## Parameters

### `ADDRESS` [out]

A pointer to a location in which to store the ULONG_PTR value.

### `VALUE` [in]

Specifies the ULONG_PTR value to be stored.

## Remarks

**RtlStoreUlongPtr** avoids memory alignment faults. If the value of _Address_ is not aligned to the storage requirements of a ULONG_PTR, **RtlStoreUlongPtr** stores the bytes of _Value_ beginning at the memory location (PUCHAR)_Address_.

**RtlStoreUlongPtr** runs at any IRQL if _Address_ points to nonpaged pool; otherwise it must run at IRQL <= APC_LEVEL.