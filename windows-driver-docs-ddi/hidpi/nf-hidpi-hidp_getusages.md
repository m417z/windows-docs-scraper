# HidP_GetUsages function

## Description

The **HidP_GetUsages** routine returns a list of all the HID control button [usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) that are on a specified [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) and are set to ON in a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UsagePage` [in]

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) of the button usages. The routine only returns information about buttons on this usage page.

### `LinkCollection` [in]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) of the button usages. If *LinkCollection* is nonzero, the routine only returns information about the buttons that this link collection contains; otherwise, if *LinkCollection* is zero, the routine returns information about all the buttons in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `UsageList` [out]

Pointer to a caller-allocated buffer that the routine uses to return the usages of all buttons that are set to ON and belong to the usage page specified by *UsagePage*.

### `UsageLength` [in, out]

Specifies, on input, the length, in array elements, of the *UsageList* buffer. Specifies, on output, the number of buttons that are set to ON on the specified usage page.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

### `Report` [out]

Pointer to a report.

### `ReportLength` [in]

Specifies the length, in bytes, of the report located at *Report*.

## Return value

**HidP_GetUsages** returns one of the following status values:

| Return code | Description |
|-------------|-------------|
| **HIDP_STATUS_SUCCESS** | The routine successfully returned all button usages set to ON. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The specified report type is not valid. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | The *UsageList* buffer is too small to hold all the usages that are currently set to ON on the specified usage page. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | The collection contains buttons on the specified usage page in a report of the specified type, but there are no such usages in the specified report. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The collection does not contain any buttons on the specified usage page in any report of the specified report type. |

## Remarks

User-mode applications and kernel-mode drivers call [HidP_MaxUsageListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxusagelistlength) to determine the maximum number of buttons that can be returned for specified report type. Alternatively, applications or drivers can call **HidP_GetUsages** and set *(\*UsageLength)* to zero to return the required length in *UsageLength*. In other words, *UsageLength* should be a valid pointer that points to a ULONG value **0** to get the required length.

Applications or drivers determine the required report length from the *Xxx***ReportByteLength** members in a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

- [HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)
- [HidP_GetButtonsEx](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [HidP_GetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getscaledusagevalue)
- [HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue)
- [HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray)
- [HidP_GetUsagesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex)
- [HidP_MaxUsageListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxusagelistlength)
- [_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)