## Description

This structure stores WHEA error report data.

## Members

### `Version`

Not currently used.

### `Data`

A pointer to a buffer containing data to be added to the body of the section.

### `DataSize`

Length, in bytes, of buffer specified by *Data*. Must be equal to *SectionDataLength* specified in [**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver).

### `SectionTypeGuid`

A GUID used in the header of the section for differentiation, and by tools like Dumprec for parsing records.

### `SectionFriendlyName`

Pointer to a string containing a human readable name added to the header information.

### `Flags`

Not currently used.

## Remarks

[**WheaAddHwErrorReportSectionDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaaddhwerrorreportsectiondevicedriver) takes as a parameter a pointer to a structure of this type. Upon success, it stores data in the structure.

## See also