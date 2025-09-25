## Description

The **RtlStoreUlonglong** macro stores a specified ULONGLONG value at a specified memory address, avoiding memory alignment faults.

## Parameters

### `ADDRESS` [out]

A pointer to a location in which to store the specified ULONGLONG value.

### `VALUE` [in]

The ULONGLONG value to be stored.

## Remarks

**RtlStoreUlonglong** avoids memory alignment faults. If the address specified by _Address_ is not aligned to the storage requirements of a ULONGLONG, **RtlStoreUlonglong** stores the bytes of _Value_ beginning at the memory location (PUCHAR)_Address_.

**RtlStoreUlonglong** runs at any IRQL if _Address_ points to nonpaged pool; otherwise, it must run at IRQL <= APC_LEVEL.