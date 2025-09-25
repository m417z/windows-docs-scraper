# _WHEA_XPF_NMI_DESCRIPTOR structure

## Description

The WHEA_XPF_NMI_DESCRIPTOR structure describes a nonmaskable interrupt (NMI) error source for an x86 or x64 processor.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFNMI.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

## Remarks

A WHEA_XPF_NMI_DESCRIPTOR structure is contained within the [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)