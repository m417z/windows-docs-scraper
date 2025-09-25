# _WHEA_IPF_MCA_DESCRIPTOR structure

## Description

The WHEA_IPF_MCA_DESCRIPTOR structure describes a machine check abort (MCA) error source for an Itanium processor.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFMCA.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `Reserved`

Reserved for system use.

## Remarks

A WHEA_IPF_MCA_DESCRIPTOR structure is contained within the [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)