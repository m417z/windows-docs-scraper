# _WHEA_GENERIC_ERROR structure

## Description

The WHEA_GENERIC_ERROR structure describes error status data for a generic error source.

## Members

### `BlockStatus`

A [WHEA_GENERIC_ERROR_BLOCKSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_blockstatus) union that indicates what kind of error data is reported in the generic error status block.

### `RawDataOffset`

The offset, in bytes, from the beginning of the WHEA_GENERIC_ERROR structure to the beginning of the raw error data.

### `RawDataLength`

The length, in bytes, of the raw error data that is located at the offset specified in the **RawDataOffset** member.

### `DataLength`

The size, in bytes, of the error data contained in the **Data** member.

### `ErrorSeverity`

A [WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)-typed value that indicates the severity of the error condition.

### `Data`

A variable-sized buffer that contains the error data from the generic error source. This buffer contains the generic error status block followed by the raw error data.

## Remarks

A generic error source is described by a [WHEA_GENERIC_ERROR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor) structure. The **ErrStatusAddress** member of the WHEA_GENERIC_ERROR_DESCRIPTOR structure points to a register that contains the physical address of a WHEA_GENERIC_ERROR structure in firmware reserved memory. This WHEA_GENERIC_ERROR structure contains the error status data for the generic error source.

A WHEA_GENERIC_ERROR structure is included in the **RawData** member of a [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure whenever the **RawDataFormat** member of the WHEA_ERROR_PACKET structure contains **WheaRawDataFormatGeneric**.

## See also

[WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[WHEA_ERROR_SEVERITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_whea_error_severity)

[WHEA_GENERIC_ERROR_BLOCKSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_blockstatus)

[WHEA_GENERIC_ERROR_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor)