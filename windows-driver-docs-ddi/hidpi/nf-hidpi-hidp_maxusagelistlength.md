# HidP_MaxUsageListLength function

## Description

The **HidP_MaxUsageListLength** routine returns the maximum number of [HID usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) that [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) can return for a specified type of HID report and a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the report type.

### `UsagePage` [in]

Specifies a [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) as a search criteria. If *UsagePage* is zero, the routine returns the number of all the buttons in the collection.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

If successful, **HidP_MaxUsageListLength** returns the maximum number of [HID usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) that [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) can return for a specified type of HID report and a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections). If the specified preparsed data or report type is not valid, the routine returns zero.

## Remarks

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)