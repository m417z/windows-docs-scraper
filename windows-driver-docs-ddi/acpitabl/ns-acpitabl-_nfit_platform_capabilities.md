## Description

Describes the NVDIMM Firmware Interface Table (NFIT) platform capabilities structure. Originally defined in ACPI 6.2 Errata A.

## Members

### `Header`

Defines a **NFIT_STRUCT_HEADER** member **Header**.

### `HighestValidCapability`

Defines a **UCHAR** member **HighestValidCapability**.

### `Reserved`

Reserved for future use.

### `Capabilities`

Defines a union member **Capabilities**.

### `Capabilities.AsUlong`

Defines a **ULONG** member **AsUlong**.

### `Capabilities.u`

Defines a structure member **u**.

### `Capabilities.u.CpuCacheFlushOnPowerLoss`

Defines a **ULONG** member **CpuCacheFlushOnPowerLoss**.

### `Capabilities.u.MemCtrlrFlushOnPowerLoss`

Defines a **ULONG** member **MemCtrlrFlushOnPowerLoss**.

### `Capabilities.u.PmemHardwareMirroring`

Defines a **ULONG** member **PmemHardwareMirroring**.

### `Reserved1`

Reserved for future use.

## Remarks

## See also