# HidP_SetUsageValue function

## Description

The **HidP_SetUsageValue** routine sets a HID control value in a specified HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of HID report located at *Report*.

### `UsagePage` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of a usage.

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usage. If *LinkCollection* is nonzero, the routine only sets the usage, if one exists, in this link collection. If *LinkCollection* is zero, the routine sets the first usage it finds in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `Usage` [in]

Specifies the usage.

### `UsageValue` [in]

Specifies the usage value.

### `PreparsedData` [in]

Pointer to a top-level's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [in, out]

Pointer to a HID report.

### `ReportLength` [in]

Specifies the size, in bytes, of the HID report located at *Report*, which must be equal to the report length for the specified report type that [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) returns in a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_SetUsageValue** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully set the usage value. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The usage does not exist in the specified report, but it does exist in a different report of the specified type. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_REPORT_DOES_NOT_EXIST** | There are no reports of the specified type. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The usage does not exist in any report of the specified report type. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |

## Remarks

**HidP_SetUsageValue** routine does not sign the value. A user-mode application or kernel-mode driver must either sign the value, at the position provided in the [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps) structure for this value, or call [HidP_SetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setscaledusagevalue).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)

[HidP_SetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setscaledusagevalue)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)