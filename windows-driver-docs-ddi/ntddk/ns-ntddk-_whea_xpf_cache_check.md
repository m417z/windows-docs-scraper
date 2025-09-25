# _WHEA_XPF_CACHE_CHECK structure

## Description

The WHEA_XPF_CACHE_CHECK union describes cache error information for an x86 or x64 processor.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.TransactionTypeValid`

A single bit that indicates that the **TransactionType** member contains valid data.

### `DUMMYSTRUCTNAME.OperationValid`

A single bit that indicates that the **Operation** member contains valid data.

### `DUMMYSTRUCTNAME.LevelValid`

A single bit that indicates that the **Level** member contains valid data.

### `DUMMYSTRUCTNAME.ProcessorContextCorruptValid`

A single bit that indicates that the **ProcessorContextCorrupt** member contains valid data.

### `DUMMYSTRUCTNAME.UncorrectedValid`

A single bit that indicates that the **Uncorrected** member contains valid data.

### `DUMMYSTRUCTNAME.PreciseIPValid`

A single bit that indicates that the **PreciseIP** member contains valid data.

### `DUMMYSTRUCTNAME.RestartableIPValid`

A single bit that indicates that the **RestartableIP** member contains valid data.

### `DUMMYSTRUCTNAME.OverflowValid`

A single bit that indicates that the **Overflow** member contains valid data.

### `DUMMYSTRUCTNAME.ReservedValid`

Reserved for system use.

### `DUMMYSTRUCTNAME.TransactionType`

The type of transaction that was in progress when the error occurred. Possible values are:

This member contains valid data only if the **TransactionTypeValid** bit is set.

### `DUMMYSTRUCTNAME.Operation`

The type of cache operation that caused the error. Possible values are:

This member contains valid data only if the **OperationValid** bit is set.

### `DUMMYSTRUCTNAME.Level`

The level of the cache where the error occurred.

This member contains valid data only if the **LevelValid** bit is set.

### `DUMMYSTRUCTNAME.ProcessorContextCorrupt`

A single bit that indicates that the processor context might have been corrupted.

This member contains valid data only if the **ProcessorContextCorruptValid** bit is set.

### `DUMMYSTRUCTNAME.Uncorrected`

A single bit that indicates that the error has not been corrected.

This member contains valid data only if the **UncorrectedValid** bit is set.

### `DUMMYSTRUCTNAME.PreciseIP`

A single bit that indicates that the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure that contains this WHEA_XPF_CACHE_CHECK union is directly associated with the error.

This member contains valid data only if the **PreciseIPValid** bit is set.

### `DUMMYSTRUCTNAME.RestartableIP`

A single bit that indicates that program execution can be restarted reliably at the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) union that contains this WHEA_XPF_CACHE_CHECK structure.

This member contains valid data only if the **RestartableIPValid** bit is set.

### `DUMMYSTRUCTNAME.Overflow`

A single bit that indicates that an error overflow occurred.

This member contains valid data only if the **OverflowValid** bit is set.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `XpfCacheCheck`

A ULONGLONG representation of the contents of the WHEA_XPF_CACHE_CHECK union.

##### - Operation.XPF_CACHE_CHECK_OPERATION_DATAREAD

A data read operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_DATAWRITE

A data write operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_EVICTION

An eviction operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_GENERIC

The type of operation cannot be determined.

##### - Operation.XPF_CACHE_CHECK_OPERATION_GENREAD

A generic read operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_GENWRITE

A generic write operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_INSTRUCTIONFETCH

An instruction fetch operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_PREFETCH

An instruction prefetch operation.

##### - Operation.XPF_CACHE_CHECK_OPERATION_SNOOP

A snoop operation.

##### - TransactionType.XPF_CACHE_CHECK_TRANSACTIONTYPE_DATAACCESS

A data access transaction.

##### - TransactionType.XPF_CACHE_CHECK_TRANSACTIONTYPE_GENERIC

A generic transaction.

##### - TransactionType.XPF_CACHE_CHECK_TRANSACTIONTYPE_INSTRUCTION

A processor instruction transaction.

## Remarks

If the **CheckInfoId** member of a [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure contains WHEA_CACHECHECK_GUID, the **CheckInfo** member of the WHEA_XPF_PROCINFO structure contains a WHEA_XPF_CACHE_CHECK union.

## See also

[WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)