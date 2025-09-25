# HidP_GetScaledUsageValue function

## Description

The **HidP_GetScaledUsageValue** routine returns the signed and scaled result of a HID control value extracted from a HID report.

## Parameters

### `ReportType` [in]

Specifies a **HIDP_REPORT_TYPE** enumerator value that identifies the type of HID report that contains the [HID usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) value.

### `UsagePage` [in]

Specifies the usage page of the value to extract.

### `LinkCollection` [in]

Specifies the link collection identifier of the value to extract. A LinkCollection value of zero identifies the top-level collection.

### `Usage` [in]

Specifies the usage of the value to extract.

### `UsageValue` [out]

Pointer to the buffer in which the routine returns the signed and scaled value.

### `PreparsedData` [in]

Pointer to the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) that generated the report located at *Report*.

### `Report` [in]

Pointer to the report that contains the usage.

### `ReportLength` [in]

Specifies the length, in bytes, of the report located at *Report*.

## Return value

**HidP_GetScaledUsageValue** returns one of the following status values:

| Return code | Description |
|--|--|
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the value. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The specified report length is not valid. |
| **HIDP_STATUS_BAD_LOG_PHY_VALUES** | The collection returned an illegal logical or physical value. To extract the value returned by the collection, call [HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue). |
| **HIDP_STATUS_NULL** | The current state of the scaled value from the collection is less than the logical minimum or is greater than the logical maximum, and the scaled value has a **NULL** state. |
| **HIDP_STATUS_VALUE_OUT_OF_RANGE** | The current state of the scaled value data from the collection is less than the logical minimum or is greater than the logical maximum. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The specified usage, usage page, or link collection cannot be found in any report supported by the specified top-level collection. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The specified value is not contained in the specified report, but is contained in another report supported by the specified top-level collection. |

## Remarks

Scaled values refer to the adjusted output of raw HID data, which are modified based on specific parameters such as sensitivity and the range of the device. This adjustment allows for more meaningful interpretation of the data in relation to the device's intended use.

For further understanding of how HID reports are interpreted and the significance of scaled values, see [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports).

The caller-allocated buffers supplied at *PreparsedData*, *UsageValue*, and *Report* must be allocated from nonpaged pool.

User-mode applications and kernel-mode drivers must use **[HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray)** to extract data for a [usage value array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays).

If the routine returns status HIDP_STATUS_BAD_LOG_PHY_VALUES, an application or driver can call **[HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue)** to extract the raw usage data.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

- [HID usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages)
- [Preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data)
- [Top-level collections](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections)
- [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports)
- [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections)
- **[HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue)**
- **[HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray)**
- **[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)**