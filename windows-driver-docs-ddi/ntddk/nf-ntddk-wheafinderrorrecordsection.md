## Description

The **WheaFindErrorRecordSection** function searches for a specified Windows Hardware Error Architecture (WHEA) error record section within a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). The error record section is formatted as a [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure.

## Parameters

### `Record` [in]

A pointer to a WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) that is formatted as a [**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record) structure.

### `SectionType` [in]

A GUID that specifies the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure to be located within the specified WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records).

### `SectionDescriptor` [out]

The address of a [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) pointer.

If the **WheaFindErrorRecordSection** function locates the specified WHEA_ERROR_RECORD_SECTION_DESCRIPTOR structure, the function sets the *SectionDescriptor* parameter to the address of that structure within the specified WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records).

### `SectionData` [out, optional]

The address of a PVOID pointer.

If the **WheaFindErrorRecordSection** function locates the specified [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure, the function sets the *SectionData* parameter to the address of the hardware error data associated with that descriptor within the specified WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records).

This parameter is optional and must be set to **NULL** if a pointer to the hardware error data is not required.

## Return value

**WheaFindErrorRecordSection** returns one of the following NTSTATUS codes:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The specified [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure was found. |
| **STATUS_NOT_FOUND** | The specified [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure was not found. |
| **STATUS_INVALID_PARAMETER** | Either the *Record*, *SectionType,* or *SectionDescriptor* parameters were set to **NULL**, or the WHEA [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records) referenced through the *Record* parameter is invalid. |

## Remarks

If **WheaFindErrorRecordSection** returns STATUS_SUCCESS, it has located the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure that was specified through the *Guid* parameter. **WheaFindErrorRecordSection** sets the *SectionDescriptor* parameter to the address of the located **WHEA_ERROR_RECORD_SECTION_DESCRIPTOR** structure.

Additionally, if **WheaFindErrorRecordSection** returns STATUS_SUCCESS and the caller set the *SectionData* parameter to the address of a PVOID pointer variable, the function updates the parameter with the address of the hardware error data associated with the specified [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure.

The format of the hardware error data is dependent upon the **SectionType** member of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure referenced through the *SectionDescriptor* parameter. For example, if the **SectionType** member has the value PROCESSOR_GENERIC_ERROR_SECTION_GUID, the hardware error data is formatted as a [**WHEA_PROCESSOR_GENERIC_ERROR_SECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_processor_generic_error_section) structure.

## See also

[Error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records)

[**WHEA_ERROR_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record)

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)