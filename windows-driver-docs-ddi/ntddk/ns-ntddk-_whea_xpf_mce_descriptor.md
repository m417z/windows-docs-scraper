## Description

The **WHEA_XPF_MCE_DESCRIPTOR** structure describes a machine check exception (MCE) error source for an x86 or x64 processor.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFMCE.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `NumberOfBanks`

The number of [**WHEA_XPF_MC_BANK_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor) structures contained in the **Banks** member.

### `Flags`

An **XPF_MCE_FLAGS** union that indicates which of the members of the WHEA_XPF_MCE_DESCRIPTOR structure can be written to by the operating system. The **XPF_MCE_FLAGS** union is defined as follows:

```cpp
typedef union _XPF_MCE_FLAGS {
  struct {
    UCHAR  MCG_CapabilityRW:1;
    UCHAR  MCG_GlobalControlRW:1;
    UCHAR  Reserved:30;
  };
  UCHAR  AsULONG;
} XPF_MCE_FLAGS, *PXPF_MCE_FLAGS;
```

#### MCG_CapabilityRW

A single bit that indicates that the operating system can write to the **MCG_Capability** member of the **WHEA_XPF_MCE_DESCRIPTOR** structure.

#### MCG_GlobalControlRW

A single bit that indicates that the operating system can write to the **MCG_GlobalControl** member of the **WHEA_XPF_MCE_DESCRIPTOR** structure.

#### Reserved

Reserved for system use.

#### AsULONG

A **ULONG** representation of the contents of the **XPF_MCE_FLAGS** union.

### `MCG_Capability`

The contents of the processor's IA32_MCG_CAP model-specific register. This register contains capability information about the machine check architecture of the processor. For more information about the IA32_MCG_CAP register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `MCG_GlobalControl`

The contents of the processor's IA32_MCG_CTL model-specific register. This register controls the reporting of machine check exceptions. For more information about the IA32_MCG_CTL register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `Banks`

An array of [**WHEA_XPF_MC_BANK_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor) structures that describe the banks of machine check registers.

## Remarks

A WHEA_XPF_MCE_DESCRIPTOR structure is contained within the [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_XPF_MC_BANK_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor)