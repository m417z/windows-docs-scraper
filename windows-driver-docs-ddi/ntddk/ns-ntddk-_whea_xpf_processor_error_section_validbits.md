# _WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS structure

## Description

The WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS union describes which members of a [WHEA_XPF_PROCESSOR_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_processor_error_section) structure contain valid data and the number of structures that are contained in the WHEA_XPF_PROCESSOR_ERROR_SECTION structure's **VariableInfo** member.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.LocalAPICId`

A single bit that indicates that the **LocalAPICId** member of the WHEA_XPF_PROCESSOR_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.CpuId`

A single bit that indicates that the **CpuId** member of the WHEA_XPF_PROCESSOR_ERROR_SECTION structure contains valid data.

### `DUMMYSTRUCTNAME.ProcInfoCount`

The number of [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo) structures that are contained in the WHEA_XPF_PROCESSOR_ERROR_SECTION structure's **VariableInfo** member.

### `DUMMYSTRUCTNAME.ContextInfoCount`

The number of [WHEA_XPF_CONTEXT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info) structures that are contained in the WHEA_XPF_PROCESSOR_ERROR_SECTION structure's **VariableInfo** member.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `ValidBits`

A ULONGLONG representation of the contents of the WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS union.

## Remarks

A WHEA_XPF_PROCESSOR_ERROR_SECTION_VALIDBITS union is contained within the [WHEA_XPF_PROCESSOR_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_processor_error_section) structure.

## See also

- [WHEA_XPF_CONTEXT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info)
- [WHEA_XPF_PROCESSOR_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_processor_error_section)
- [WHEA_XPF_PROCINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_procinfo)