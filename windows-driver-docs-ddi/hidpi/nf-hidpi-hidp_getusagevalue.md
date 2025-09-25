# HidP_GetUsageValue function

## Description

The **HidP_GetUsageValue** routine extracts the data associated with a HID control value that matches the selection criteria in a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UsagePage` [in]

Specifies the value's [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the value. If *LinkCollection* is nonzero, the routine only searches for the usage in this link collection; otherwise, if *LinkCollection* is zero, the routine searches for the usage in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `Usage` [in]

Specifies the usage of the value.

### `UsageValue` [out]

Pointer to a buffer in which the routine returns the value data.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [in]

Pointer to a report that contains values.

### `ReportLength` [in]

Specifies the length, in bytes, of the report located at *Report*.

## Return value

**HidP_GetUsageValue** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the value data. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The collection contains a value on the specified usage page in a report of the specified type, but there are no such usages in the specified report. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The collection does not contain a value on the specified usage page in any report of the specified report type. |

## Remarks

**HidP_GetUsageValue** does not sign or scale the value. To extract a signed value, use **HidP_GetScaledUsageValue**. To manually assign the sign bit, the position of the sign bit can be determined from the information in a value's [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps) structure.

**HidP_GetUsageValue** is designed to extract a usage value for a usage whose report count is 1. If the specified usage has a report count greater than 1, the usage is part of a [usage value array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays). **HidP_GetUsageValue** only returns the first data item in a usage value array. To extract all data items in a usage value array, use [HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)

[HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_GetButtonsEx](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[HidP_GetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getscaledusagevalue)

[HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray)

[HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)

[HidP_GetUsagesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)