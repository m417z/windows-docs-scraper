# HidP_InitializeReportForID function

## Description

The **HidP_InitializeReportForID** routine initializes a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator that indicates the type of HID report located at *Report*.

### `ReportID` [in]

Specifies a report ID.

### `PreparsedData` [in]

Pointer to the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with the HID report located at *Report*.

### `Report` [out]

Pointer to the caller-allocated buffer containing the HID report that **HidP_InitializeReportForID** initializes.

### `ReportLength` [in]

Specifies the size, in bytes, of the HID report located at *Report*. *ReportLength* must be equal to the collection's report length for the specified report type, as specified by the *Xxx***ReportByteLength** members of a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_InitializeReportForID** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The report was successfully initialized. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The specified length of the report is not equal to the collection's report length for the specified report type. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The report type is not valid. |
| **HIDP_STATUS_REPORT_DOES_NOT_EXIST** | The specified report ID is not valid. |

## Remarks

Initializing a HID report sets all control data to zero or a control's *null value*, as defined by the USB HID standard. (Sending or receiving a null value indicates that the current value of a control should not be modified.)

**HidP_InitializeReportForID** does the following:

* Sets to zero the bitfields of all buttons and values without null values.
* Sets the bitfield of all controls with null values to their corresponding null value.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)

[HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)