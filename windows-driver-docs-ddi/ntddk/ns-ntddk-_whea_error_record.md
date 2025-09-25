## Description

The **WHEA_ERROR_RECORD** structure describes an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) that contains error information about a hardware error condition that occurred.

## Members

### `Header`

A [**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure that describes general information about the hardware error condition.

### `SectionDescriptor`

A variable sized array of [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe each of the sections of error information that are contained in the error record. The number of structures in the array is specified by the **Header.SectionCount** member of the WHEA_ERROR_RECORD structure.

## Remarks

When a hardware error occurs, WHEA creates an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) to store the error information associated with the hardware error condition. Each error record is described by a WHEA_ERROR_RECORD structure. The Windows kernel includes the error record with the Event Tracing for Windows (ETW) hardware error event that it raises in response to the error so that the error record is saved in the system event log.

The format of the error records that are used by WHEA are based on the *Common Platform Error Record* as described in Appendix N of version 2.2 of the [Unified Extensible Firmware Interface (UEFI) Specification](https://uefi.org/specifications).

A user-mode application can retrieve the error record from the hardware error event for analysis. For more information about how to develop an application to retrieve error records from hardware error events, see [WHEA Hardware Error Event Processing Applications](https://learn.microsoft.com/windows-hardware/drivers/whea/whea-hardware-error-event-processing-applications).

## See also

[**WHEA_ERROR_RECORD_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)