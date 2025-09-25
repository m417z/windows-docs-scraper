# FsRtlInitializeBaseMcb function

## Description

**FsRtlInitializeBaseMcb** initializes a new map control block (MCB) structure.

## Parameters

### `Mcb`

Pointer to the MCB structure to initialize.

### `PoolType`

Specifies the pool type to use when allocating additional internal MCB memory.

## Remarks

The caller supplies the memory for the MCB structure. A call to **FsRtlInitializeBaseMcb** must precede all other calls that set/query the MCB structure.

If pool is not available, this routine will raise a status value indicating insufficient resources.

## See also

[FsRtlInitializeBaseMcbEx function](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializebasemcbex)