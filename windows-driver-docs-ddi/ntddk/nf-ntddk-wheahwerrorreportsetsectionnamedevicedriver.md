## Description

This is a helper function for updating the FRUText field of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structure.

## Parameters

### `BufferSet`

Pointer to the buffer set received from [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver).

### `NameLength`

Length of the supplied string.

### `Name`

Pointer to a string with which to populate the FRUText section.

## Return value

Return STATUS_SUCCESS or an error code.

## Remarks

Sections in a Common Platform Error Record (CPER) have Field Replaceable Unit (FRU) text, or *FRUText*. For details on CPER, see [Error Records](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records).

First call [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver).

Then call this function with the buffer set from [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver), along with a string and its length and it will populate the FRUText field of [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) with the string.

## See also