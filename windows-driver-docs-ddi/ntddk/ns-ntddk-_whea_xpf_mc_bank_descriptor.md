## Description

The **WHEA_XPF_MC_BANK_DESCRIPTOR** structure describes a bank of machine check registers for an x86 or x64 processor.

## Members

### `BankNumber`

The processor machine check register bank number.

### `ClearOnInitialization`

A Boolean value that indicates that the status registers for the bank are to be cleared by the operating system during initialization.

### `StatusDataFormat`

The format of the data in the register bank's status register. Possible values are:

#### WHEA_XPF_MC_BANK_STATUSFORMAT_IA32MCA

IA32 machine check architecture.

#### WHEA_XPF_MC_BANK_STATUSFORMAT_Intel64MCA

Intel64 machine check architecture.

#### WHEA_XPF_MC_BANK_STATUSFORMAT_AMD64MCA

AMD64 machine check architecture.

### `Flags`

An **XPF_MC_BANK_FLAGS** union that indicates which of the members of the **WHEA_XPF_MC_BANK_DESCRIPTOR** structure can be written to by the operating system. The **XPF_MC_BANK_FLAGS** union is defined as follows:

```cpp
typedef union _XPF_MC_BANK_FLAGS {
  struct {
    UCHAR  ClearOnInitializationRW:1;
    UCHAR  ControlDataRW:1;
    UCHAR  Reserved:6;
  };
  UCHAR  AsUCHAR;
} XPF_MC_BANK_FLAGS, *PXPF_MC_BANK_FLAGS;
```

#### ClearOnInitializationRW

A single bit that indicates that the operating system can write to the **ClearOnInitialization** member of the **WHEA_XPF_MC_BANK_DESCRIPTOR** structure.

#### ControlDataRW

A single bit that indicates that the operating system can write to the **ControlData** member of the **WHEA_XPF_MC_BANK_DESCRIPTOR** structure.

#### Reserved

Reserved for system use.

#### AsUCHAR

A UCHAR representation of contents of the **XPF_MC_BANK_FLAGS** union.

### `ControlMsr`

The model-specific register address of the register bank's IA32_MCi_CTL register. For more information about the IA32_MCi_CTL register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `StatusMsr`

The model-specific register address of the register bank's IA32_MCi_STATUS register. For more information about the IA32_MCi_STATUS register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `AddressMsr`

The model-specific register address of the register bank's IA32_MCi_ADDR register. For more information about the IA32_MCi_ADDR register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `MiscMsr`

The model-specific register address of the register bank's IA32_MCi_MISC register. For more information about the IA32_MCi_MISC register, see the [Intel 64 and IA-32 Architectures Software Developer's Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html).

### `ControlData`

The value that the operating system writes to the register bank's control register during initialization.

## Remarks

An array of WHEA_XPF_MC_BANK_DESCRIPTOR structures is contained in the [**WHEA_XPF_CMC_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor) and [**WHEA_XPF_MCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mce_descriptor) structures.

## See also

[**WHEA_XPF_CMC_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor)

[**WHEA_XPF_MCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mce_descriptor)