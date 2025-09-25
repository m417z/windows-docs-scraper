# _WHEA_XPF_PROCINFO structure

## Description

The WHEA_XPF_PROCINFO structure describes processor error information that is specific to the x86 and x64 processor architectures.

## Members

### `CheckInfoId`

A GUID that identifies the processor error information that is contained in the **CheckInfo** member. The following are the possible GUIDs that can be specified for this member:

#### WHEA_CACHECHECK_GUID

The **CheckInfo.CacheCheck** member contains cache error information.

#### WHEA_TLBCHECK_GUID

The **CheckInfo.TlbCheck** member contains translation lookaside buffer error information.

#### WHEA_BUSCHECK_GUID

The **CheckInfo.BusCheck** member contains bus error information.

#### WHEA_MSCHECK_GUID

The **CheckInfo.MsCheck** member contains microarchitecture-specific error information.

### `ValidBits`

A [WHEA_XPF_PROCINFO_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo_validbits) union that specifies which members of this structure contain valid data.

### `CheckInfo`

A union of unions that are specific to each different type of processor error information.

This member contains valid data only if the **ValidBits.CheckInfo** bit is set.

### `CheckInfo.CacheCheck`

A [WHEA_XPF_CACHE_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cache_check) union that describes cache error information.

### `CheckInfo.TlbCheck`

A [WHEA_XPF_TLB_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_tlb_check) union that describes translation lookaside buffer error information.

### `CheckInfo.BusCheck`

A [WHEA_XPF_BUS_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_bus_check) union that describes bus error information.

### `CheckInfo.MsCheck`

A [WHEA_XPF_MS_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_ms_check) union that describes microarchitecture-specific error information.

### `CheckInfo.AsULONGLONG`

A ULONGLONG representation of the contents of the **CheckInfo** union.

### `TargetId`

An identifier that uniquely identifies the target associated with the error.

This member contains valid data only if the **ValidBits.TargetId** bit is set.

### `RequesterId`

An identifier that uniquely identifies the requester associated with the error.

This member contains valid data only if the **ValidBits.RequesterId** bit is set.

### `ResponderId`

An identifier that uniquely identifies the responder associated with the error.

This member contains valid data only if the **ValidBits.Responder** bit is set.

### `InstructionPointer`

The instruction pointer at the time that the error occurred.

This member contains valid data only if the **ValidBits.InstructionPointer** bit is set.

## Remarks

The [WHEA_XPF_PROCESSOR_ERROR_SECTION](https://learn.microsoft.com/previous-versions/ff560655(v=vs.85)) structure contains an array of WHEA_XPF_PROCINFO structures, each of which describes specific error information associated with the processor error that occurred.

## See also

[WHEA_XPF_BUS_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_bus_check)

[WHEA_XPF_CACHE_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cache_check)

[WHEA_XPF_MS_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_ms_check)

[WHEA_XPF_PROCESSOR_ERROR_SECTION](https://learn.microsoft.com/previous-versions/ff560655(v=vs.85))

[WHEA_XPF_PROCINFO_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo_validbits)

[WHEA_XPF_TLB_CHECK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_tlb_check)