# HidP_SetScaledUsageValue function

## Description

The **HidP_SetScaledUsageValue** routine converts a signed and scaled physical number to a [HID usage's](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) logical value, and sets the usage value in a specified HID report.

## Parameters

### `ReportType` [in]

Specifies a **[HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type)** enumerator value that indicates the type of HID report located at *Report*.

### `UsagePage` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of a usage.

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usage. If *LinkCollection* is nonzero, the routine only sets the usage, if one exists, in this link collection. If *LinkCollection* is zero, the routine sets the first usage it finds in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `Usage` [in]

Specifies the usage.

### `UsageValue` [in]

Specifies the signed and scaled physical number, which the routine converts to the usage's logical value.

### `PreparsedData` [in]

Pointer to a top-level's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [in, out]

Pointer to a HID report.

### `ReportLength` [in]

Specifies the size, in bytes, of the HID report located at *Report*, which must be equal to the report length for the specified report type that **[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)** returns in a collection's **[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)** structure.

## Return value

**HidP_SetScaledUsageValue** returns one of the following status values:

| Return code | Description |
|--|--|
| **HIDP_STATUS_SUCCESS** | The routine successfully set the usage value. |
| **HIDP_STATUS_BAD_LOG_PHY_VALUES** | The usage has an illegal logical or physical range that prevents scaling. |
| **HIDP_STATUS_VALUE_OUT_OF_RANGE** | The specified physical value is out-of-range and the usage does not have null value. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The usage does not exist in the specified report, but it does exist in a different report of the specified type. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The usage does not exist in any report of the specified report type. |
| **HIDP_STATUS_NULL** | The specified physical value is out-of-range, the usage has a null value, and the routine set the null value. |

## Remarks

Scaled values refer to the adjusted output of raw HID data, which are modified based on specific parameters such as sensitivity and the range of the device. This adjustment allows for more meaningful interpretation of the data in relation to the device's intended use.

For further understanding of how HID reports are interpreted and the significance of scaled values, see [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports).

**HidP_SetScaledUsageValue** sets the sign bit.

If the routine returns HIDP_STATUS_INCOMPATIBLE_REPORT_ID, the specified report does contain the usage. However, a user-mode application or kernel-mode driver can set the usage in a zero-initialized report. See [Initializing HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/initializing-hid-reports).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

- [HID usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages)
- [Link collections](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections)
- [Top-level collections](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections)
- [Preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data)
- [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports)
- [Initializing HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/initializing-hid-reports)
- [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections)
- **[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)**
- **[HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type)**
- **[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)**
- **[HidP_SetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevalue)**
- **[HidP_SetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevaluearray)**
- **[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)**