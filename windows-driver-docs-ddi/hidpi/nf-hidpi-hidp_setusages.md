# HidP_SetUsages function

## Description

The **HidP_SetUsages** routine sets specified HID control buttons ON (1) in a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of report located at *Report*.

### `UsagePage` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) for the usages specified by *UsageList*.

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usages. If *LinkCollection* is nonzero, the routine only sets the usages, if they exist, in this link collection. If *LinkCollection* is zero, the routine sets the first usage for each specified usage in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `UsageList` [in, out]

Pointer to the array of usages.

### `UsageLength` [in, out]

Specifies, on input, the number of usages in *UsageList*. See the Remarks section for information about the output value.

### `PreparsedData` [in]

Pointer to the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the top-level collection associated with the report located at *Report*.

### `Report` [in]

Pointer to a report.

### `ReportLength` [in]

Specifies the size, in bytes, of the report located at *Report*, which must be equal to the report length for the specified report type that [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) returns in a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_SetUsages** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully set the usage value. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | A usage in a button array cannot be set because the array is already fully set. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | A usage does not exist in the specified report, but it does exist in a different report of the specified type. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | A usage does not exist in any report of the specified report type. |

## Remarks

If **HidP_SetUsages** cannot set a usage in *UsageList*, the routine sets *UsageLength* to the index of the usage that could not be set, and returns a status value that indicates the error.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)

[HidP_SetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_UnsetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_UnsetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_unsetusages)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)