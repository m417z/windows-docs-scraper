# _WHEA_XPF_PROCINFO_VALIDBITS structure

## Description

The WHEA_XPF_PROCINFO_VALIDBITS union describes which members of a [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure contain valid data.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.CheckInfo`

A single bit that indicates that the **CheckInfo** member of the WHEA_XPF_PROCINFO structure contains valid data.

### `DUMMYSTRUCTNAME.TargetId`

A single bit that indicates that the **TargetId** member of the WHEA_XPF_PROCINFO structure contains valid data.

### `DUMMYSTRUCTNAME.RequesterId`

A single bit that indicates that the **RequesterId** member of the WHEA_XPF_PROCINFO structure contains valid data.

### `DUMMYSTRUCTNAME.ResponderId`

A single bit that indicates that the **ResponderId** member of the WHEA_XPF_PROCINFO structure contains valid data.

### `DUMMYSTRUCTNAME.InstructionPointer`

A single bit that indicates that the **InstructionPointer** member of the WHEA_XPF_PROCINFO structure contains valid data.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_XPF_PROCINFO_VALIDBITS union.

## Remarks

A WHEA_XPF_PROCINFO_VALIDBITS union is contained within the [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structure.

## See also

[WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)