# FsRtlInitializeBaseMcbEx function

## Description

**FsRtlInitializeBaseMcbEx** initializes a new MCB structure.

## Parameters

### `Mcb`

Contains a pointer to the MCB structure to initialize.

### `PoolType`

Specifies the pool type to use when allocating additional internal MCB memory.

### `Flags`

A bitmask of flags that specifies what action(s) to take when a MCB mapping is empty. Contains one of the following values.

Flag | Value
--- | ---
MCB_FLAG_RAISE_ON_ALLOCATION_FAILURE | 1

## Return value

This function returns TRUE if it successfully initializes the MCB structure.

## Remarks

The caller must supply the memory for the MCB structure. This call must precede all other calls that set/query the MCB structure.

If pool is not available this routine will raise a status value indicating insufficient resources or return false depending on the flags.

## See also

[FsRtlInitializeBaseMcb function](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializebasemcb)