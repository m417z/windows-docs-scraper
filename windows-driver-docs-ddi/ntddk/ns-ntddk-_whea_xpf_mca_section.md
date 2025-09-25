## Description

**WHEA_XPF_MCA_SECTION** is a machine check exception error section structure.

## Members

### `VersionNumber`

Defines the **ULONG** member **VersionNumber**.

### `CpuVendor`

Defines the **WHEA_CPU_VENDOR** member **CpuVendor**.

### `Timestamp`

Defines the **LARGE_INTEGER** member **Timestamp**.

### `ProcessorNumber`

Defines the **ULONG** member **ProcessorNumber**.

### `GlobalStatus`

Defines the **MCG_STATUS** member **GlobalStatus**.

### `InstructionPointer`

Defines the **ULONGLONG** member **InstructionPointer**.

### `BankNumber`

Defines the **ULONG** member **BankNumber**.

### `Status`

Defines the **MCI_STATUS** member **Status**.

### `Address`

Defines the **ULONGLONG** member **Address**.

### `Misc`

Defines the **ULONGLONG** member **Misc**.

### `ExtendedRegisterCount`

Defines the **ULONG** member **ExtendedRegisterCount**.

### `ApicId`

Defines the **ULONG** member **ApicId**.

### `ExtendedRegisters[WHEA_XPF_MCA_EXTREG_MAX_COUNT]`

Defines the **ULONGLONG** member **ExtendedRegisters**.

### `AMDExtendedRegisters`

Defines the **WHEA_AMD_EXTENDED_REGISTERS** member **AMDExtendedRegisters**.

### `GlobalCapability`

Defines the **MCG_CAP** member **GlobalCapability**.

### `RecoveryInfo`

Defines the **XPF_RECOVERY_INFO** member **RecoveryInfo**.

### `ExBankCount`

Defines the **ULONG** member **ExBankCount**.

### `BankNumberEx[WHEA_XPF_MCA_EXBANK_COUNT]`

Defines the **ULONG** member **BankNumberEx**.

### `StatusEx[WHEA_XPF_MCA_EXBANK_COUNT]`

Defines the **MCI_STATUS** member **StatusEx**.

### `AddressEx[WHEA_XPF_MCA_EXBANK_COUNT]`

Defines the **ULONGLONG** member **AddressEx**.

### `MiscEx[WHEA_XPF_MCA_EXBANK_COUNT]`

Defines the **ULONGLONG** member **MiscEx**.

## Remarks

## See also