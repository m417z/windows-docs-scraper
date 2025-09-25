# HidP_SetData function

## Description

The **HidP_SetData** routine sets a specified set of HID control button and value usages in a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of HID report located at *Report*.

### `DataList` [in, out]

Pointer to a caller-allocated array of [HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data) structures that specify which buttons and usage values to set.

### `DataLength` [in, out]

Specifies, on input, the number of members in the *DataList* array. For information about the output value, see the Remarks section.

### `PreparsedData` [in]

Pointer to a top-level's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [in]

Pointer to a HID report.

### `ReportLength` [in]

Specifies the size, in bytes, of the HID report located at *Report*, which must be equal to the report length for the specified report type that [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) returns in a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_SetData** returns HIDP_STATUS_SUCCESS if it successfully sets all the control data specified by *DataList*.

**HidP_SetData** returns one of the following status values if one of the input parameters is not valid:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data specified by *PreparsedData* is not valid. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The size, in bytes, of the HID report is not equal to the length specified in the collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure for the specified report type. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | *ReportType* is not valid. |
| **HIDP_STATUS_REPORT_DOES_NOT_EXIST** | The collection does not contain a report of the specified type. |

HidP_SetData returns one of the following error values if one of the specified button or usage values could not be set:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | A button in an array was not set to ON (1) because all the array fields are already used to index other buttons. |
| **HIDP_STATUS_BUTTON_NOT_PRESSED** | A DataList member specifies to set a button OFF (zero), but the button is already set to OFF. |
| **HIDP_STATUS_DATA_INDEX_NOT_FOUND** | The data index of a DataList member is not valid. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | A button or usage value is contained in a report, but it is not in the specified report. |
| **HIDP_STATUS_IS_VALUE_ARRAY** | A data index specifies a [usage value array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays). |

## Remarks

Except for usage value arrays, a user-mode application or kernel-mode driver can use **HidP_SetData** to set buttons and usage values in a report. To set a usage value array, an application or driver must use [HidP_SetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevaluearray).

**HidP_SetData** sets the output value of *DataLength* as follows:

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data)

[HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata)

[HidP_SetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_SetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevaluearray)

[HidP_SetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages)

[HidP_UnsetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_UnsetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_unsetusages)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)