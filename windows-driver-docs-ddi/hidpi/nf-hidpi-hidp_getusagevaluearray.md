# HidP_GetUsageValueArray function

## Description

The **HidP_GetUsageValueArray** routine extracts the data associated with a HID control [usage value array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays) from a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UsagePage` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of the usage value array.

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usage value array. If *LinkCollection* is nonzero, the routine only searches for a usage value array in this link collection; otherwise, if *LinkCollection* is zero, the routine searches for a usage value array in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `Usage` [in]

Specifies the usage of the usage value array.

### `UsageValue` [in, out]

Pointer to a caller-allocated buffer in which the routine returns the data associated with the usage value array.

### `UsageValueByteLength` [in]

Specifies the length, in bytes, of the buffer at *UsageValue*.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [in]

Pointer to a report that contains values.

### `ReportLength` [in]

Specifies the length, in bytes, of the report located at *Report*.

## Return value

**HidP_GetUsageValueArray** returns one of the following status values:

| Return code | Description |
|-------------|-------------|
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the value's data. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_NOT_VALUE_ARRAY** | The requested usage is not a usage value array. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | The *UsageValue* buffer is too small to hold the requested usage. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The collection contains a usage value array on the specified usage page in a report of the specified type, but there are no such usages in the specified report. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The collection does not contain a usage value array on the specified usage page in any report of the specified report type. |

## Remarks

The required size, in bytes, of *UsageValueByteLength* is determined by multiplying together the **BitSize** and **ReportCount** members of the usage value array's [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps) structure, and rounding the result up to the nearest byte.

**HidP_GetUsageValueArray** sets the *UsageValue* buffer in little-endian order, beginning with the least significant bit of the usage's data. The data is not byte-aligned, and is shifted such that the least significant bit of the data is located at the first bit of the *UsageValue* buffer.

**HidP_GetUsageValueArray** is designed to extract all the usage values for a usage whose report count is greater than 1. To extract a usage whose report count is equal to 1, use **HidP_GetUsageValue**.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

- [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)
- [HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)
- [HidP_GetButtonsEx](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [HidP_GetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getscaledusagevalue)
- [HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue)
- [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)
- [HidP_GetUsagesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex)
- [_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)