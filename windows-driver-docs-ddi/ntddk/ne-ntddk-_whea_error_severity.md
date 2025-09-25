## Description

The **WHEA_ERROR_SEVERITY** enumeration defines the possible severity levels of a hardware error condition.

## Constants

### `WheaErrSevRecoverable`

The error has not been corrected but might be recoverable.

### `WheaErrSevFatal`

The error has not been corrected and is fatal.

### `WheaErrSevCorrected`

The error has been corrected by the hardware or firmware.

### `WheaErrSevInformational`

An error has not occurred.

## Remarks

The [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2), [**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header), [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor), and [**WHEA_GENERIC_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structures each contain a member of type WHEA_ERROR_SEVERITY that specifies the severity of the error that is described by the structure.

## See also

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_packet_v2)

[**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_GENERIC_ERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)