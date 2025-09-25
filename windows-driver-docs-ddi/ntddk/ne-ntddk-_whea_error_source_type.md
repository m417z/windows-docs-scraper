## Description

The **WHEA_ERROR_SOURCE_TYPE** enumeration defines the different types of error sources that can report hardware errors.

## Constants

### `WheaErrSrcTypeMCE`

A machine check exception (MCE).

### `WheaErrSrcTypeCMC`

A corrected machine check (CMC).

### `WheaErrSrcTypeCPE`

A corrected platform error (CPE).

### `WheaErrSrcTypeNMI`

A nonmaskable interrupt (NMI).

### `WheaErrSrcTypePCIe`

A PCI Express (PCIe) error.

### `WheaErrSrcTypeGeneric`

A type of error source that does not conform to any of the other WHEA_ERROR_SOURCE_TYPE enumeration values.

### `WheaErrSrcTypeINIT`

An Itanium processor INIT error.

### `WheaErrSrcTypeBOOT`

A boot error source.

### `WheaErrSrcTypeSCIGeneric`

A service control interrupt (SCI).

### `WheaErrSrcTypeIPFMCA`

An Itanium processor machine check abort (MCA).

### `WheaErrSrcTypeIPFCMC`

An Itanium processor corrected machine check (CMC).

### `WheaErrSrcTypeIPFCPE`

An Itanium processor corrected platform error (CPE).

### `WheaErrSrcTypeGenericV2`

Defines the **WheaErrSrcTypeGenericV2** constant.

### `WheaErrSrcTypeSCIGenericV2`

Defines the **WheaErrSrcTypeSCIGenericV2** constant.

### `WheaErrSrcTypeBMC`

A Baseboard Management Controller (BMC) error.

### `WheaErrSrcTypePMEM`

An ARS PMEM error.

### `WheaErrSrcTypeDeviceDriver`

A driver-specific error.

### `WheaErrSrcTypeSea`

Defines the **WheaErrSrcTypeSea** constant.

### `WheaErrSrcTypeSei`

Defines the **WheaErrSrcTypeSei** constant.

### `WheaErrSrcTypeMax`

The maximum number of error source types that can report hardware errors.

## Remarks

The [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure contains a member of type WHEA_ERROR_SOURCE_TYPE that specifies the type of error source that is described by the structure.

The [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure contains a member of type WHEA_ERROR_SOURCE_TYPE that specifies the type of error source that caused the error condition described by the structure.

## See also

[Windows Hardware Error Architecture Definitions](https://learn.microsoft.com/windows-hardware/drivers/whea/windows-hardware-error-architecture-definitions)

[WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)