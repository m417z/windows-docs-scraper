# _WHEA_XPF_MS_CHECK structure

## Description

The WHEA_XPF_MS_CHECK union describes microarchitecture-specific error information for an x86 or x64 processor.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ErrorTypeValid`

A single bit that indicates that the **ErrorType** member contains valid data.

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

### `DUMMYSTRUCTNAME.ReservedValue`

### `DUMMYSTRUCTNAME.ErrorType`

The type of error that occurred. Possible values are:

All other values are processor-specific.

This member contains valid data only if the **ErrorTypeValid** bit is set.

### `DUMMYSTRUCTNAME.ProcessorContextCorrupt`

A single bit that indicates that the processor context might have been corrupted.

This member contains valid data only if the **ProcessorContextCorruptValid** bit is set.

### `DUMMYSTRUCTNAME.Uncorrected`

A single bit that indicates that the error has not been corrected.

This member contains valid data only if the **UncorrectedValid** bit is set.

### `DUMMYSTRUCTNAME.PreciseIP`

A single bit that indicates that the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure that contains this WHEA_XPF_MS_CHECK union is directly associated with the error.

This member contains valid data only if the **PreciseIPValid** bit is set.

### `DUMMYSTRUCTNAME.RestartableIP`

A single bit that indicates that program execution can be restarted reliably at the instruction pointer that is specified in the **InstructionPointer** member of the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) union that contains this WHEA_XPF_MS_CHECK structure.

This member contains valid data only if the **RestartableIPValid** bit is set.

### `DUMMYSTRUCTNAME.Overflow`

A single bit that indicates that an error overflow occurred.

This member contains valid data only if the **OverflowValid** bit is set.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `XpfMsCheck`

A ULONGLONG representation of the contents of the WHEA_XPF_MS_CHECK union.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_EXTERNAL

An external error.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_FRC

A functional redundancy checking (FRC) error.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_INTERNALUNCLASSIFIED

An unclassified internal error.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_MCROMPARITY

A microcode ROM parity error.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_NOERROR

No error occurred.

##### - ErrorType.XPF_MS_CHECK_ERRORTYPE_UNCLASSIFIED

An unclassified error.

## Remarks

If the **CheckInfoId** member of a [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure contains WHEA_MSCHECK_GUID, the **CheckInfo** member of the WHEA_XPF_PROCINFO structure contains a WHEA_XPF_MS_CHECK union.

## See also

[WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)