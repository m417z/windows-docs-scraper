# _WHEA_XPF_BUS_CHECK structure

## Description

The WHEA_XPF_BUS_CHECK union describes bus error information for an x86 or x64 processor.

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

### `DUMMYSTRUCTNAME.ParticipationValid`

A single bit that indicates that the **Participation** member contains valid data.

### `DUMMYSTRUCTNAME.TimeoutValid`

A single bit that indicates that the **Timeout** member contains valid data.

### `DUMMYSTRUCTNAME.AddressSpaceValid`

A single bit that indicates that the **AddressSpace** member contains valid data.

### `DUMMYSTRUCTNAME.ReservedValid`

Reserved for system use.

### `DUMMYSTRUCTNAME.TransactionType`

The type of transaction that was in progress when the error occurred. Possible values are:

This member contains valid data only if the **TransactionTypeValid** bit is set.

### `DUMMYSTRUCTNAME.Operation`

The type of bus operation that caused the error. Possible values are:

This member contains valid data only if the **OperationValid** bit is set.

### `DUMMYSTRUCTNAME.Level`

The level of the bus hierarchy where the error occurred.

This member contains valid data only if the **LevelValid** bit is set.

### `DUMMYSTRUCTNAME.ProcessorContextCorrupt`

A single bit that indicates that the processor context might have been corrupted.

This member contains valid data only if the **ProcessorContextCorruptValid** bit is set.

### `DUMMYSTRUCTNAME.Uncorrected`

A single bit that indicates that the error has not been corrected.

This member contains valid data only if the **UncorrectedValid** bit is set.

### `DUMMYSTRUCTNAME.PreciseIP`

A single bit that indicates that the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure that contains this WHEA_XPF_BUS_CHECK union is directly associated with the error.

This member contains valid data only if the **PreciseIPValid** bit is set.

### `DUMMYSTRUCTNAME.RestartableIP`

A single bit that indicates that program execution can be restarted reliably at the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) union that contains this WHEA_XPF_BUS_CHECK structure.

This member contains valid data only if the **RestartableIPValid** bit is set.

### `DUMMYSTRUCTNAME.Overflow`

A single bit that indicates that an error overflow occurred.

This member contains valid data only if the **OverflowValid** bit is set.

### `DUMMYSTRUCTNAME.Participation`

The type of participation by the local processor. Possible values are:

This member contains valid data only if the **ParticipationValid** bit is set.

### `DUMMYSTRUCTNAME.Timeout`

A single bit that indicates that a timeout occurred.

This member contains valid data only if the **TimeoutValid** bit is set.

### `DUMMYSTRUCTNAME.AddressSpace`

The type of address space that was associated with the transaction that caused the error. Possible values are:

This member contains valid data only if the **AddressSpaceValid** bit is set.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `XpfBusCheck`

A ULONGLONG representation of the contents of the WHEA_XPF_BUS_CHECK union.

##### - AddressSpace.XPF_BUS_CHECK_ADDRESS_IO

I/O address space.

##### - AddressSpace.XPF_BUS_CHECK_ADDRESS_MEMORY

Memory address space.

##### - AddressSpace.XPF_BUS_CHECK_ADDRESS_OTHER

An unclassified type of address space.

##### - AddressSpace.XPF_BUS_CHECK_ADDRESS_RESERVED

Reserved.

##### - Operation.XPF_BUS_CHECK_OPERATION_DATAREAD

A data read operation.

##### - Operation.XPF_BUS_CHECK_OPERATION_DATAWRITE

A data write operation.

##### - Operation.XPF_BUS_CHECK_OPERATION_GENERIC

The type of operation cannot be determined.

##### - Operation.XPF_BUS_CHECK_OPERATION_GENREAD

A generic read operation.

##### - Operation.XPF_BUS_CHECK_OPERATION_GENWRITE

A generic write operation.

##### - Operation.XPF_BUS_CHECK_OPERATION_INSTRUCTIONFETCH

An instruction fetch operation.

##### - Operation.XPF_BUS_CHECK_OPERATION_PREFETCH

An instruction prefetch operation.

##### - Participation.XPF_BUS_CHECK_PARTICIPATION_GENERIC

A generic value for this member if none of the other values are applicable.

##### - Participation.XPF_BUS_CHECK_PARTICIPATION_PROCOBSERVED

The local processor observed the request.

##### - Participation.XPF_BUS_CHECK_PARTICIPATION_PROCORIGINATED

The local processor originated the request.

##### - Participation.XPF_BUS_CHECK_PARTICIPATION_PROCRESPONDED

The local processor responded to the request.

##### - TransactionType.XPF_BUS_CHECK_TRANSACTIONTYPE_DATAACCESS

A data access transaction.

##### - TransactionType.XPF_BUS_CHECK_TRANSACTIONTYPE_GENERIC

A generic transaction.

##### - TransactionType.XPF_BUS_CHECK_TRANSACTIONTYPE_INSTRUCTION

A processor instruction transaction.

## Remarks

If the **CheckInfoId** member of a [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure contains WHEA_BUSCHECK_GUID, the **CheckInfo** member of the WHEA_XPF_PROCINFO structure contains a WHEA_XPF_BUS_CHECK union.

## See also

[WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)