# HidP_GetData function

## Description

The **HidP_GetData** routine returns, for a specified report, an array of [HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data) structures that identify the [data indices](https://learn.microsoft.com/windows-hardware/drivers/hid/data-indices) of all HID control buttons that are currently set to ON (1), and the data indices and data associated with all HID control values.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of HID report located at *Report*.

### `DataList` [out]

Specifies a caller-allocated array of HIDP_DATA structures that the routine uses to return information about all the buttons that are currently set to ON and the data associated with values.

### `DataLength` [in, out]

Specifies, on input, the number of structures that the caller-allocated *DataList* array holds. Specifies, on output, the number of controls for which the routine can return data, which includes all buttons that are currently set to ON and all control values.

### `PreparsedData` [in]

Pointer to the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the top-level collection associated with the HID report located at *Report*.

### `Report` [in]

Pointer to a HID report.

### `ReportLength` [in]

Specifies the size, in bytes, of the HID report located at *Report*, which must be equal to the report length for the specified report type returned by [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) in the collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_GetData** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | All the control data was successfully returned. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The report type specified by *ReportType* is not valid |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data specified by *PreparsedData* is not valid |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The size, in bytes, of the HID report is not equal to the length specified in the collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure for the specified report type. |
| **HIDP_STATUS_REPORT_DOES_NOT_EXIST** | The top-level collection does not have a report of the specified type. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | The *DataList* array is too small to describe all the buttons, currently set to ON, and all the values in the HID report. |

## Remarks

User-mode applications and kernel-mode drivers call [HidP_MaxDataListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxdatalistlength) to determine the maximum possible number of HIDP_DATA structures that **HidP_GetData** can return.

**HidP_GetData** does not return data for [usage value arrays](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data)

[HidP_MaxDataListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxdatalistlength)

[HidP_SetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setdata)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)