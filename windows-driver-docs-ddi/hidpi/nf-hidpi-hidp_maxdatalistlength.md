# HidP_MaxDataListLength function

## Description

The **HidP_MaxDataListLength** routine returns the maximum number of [HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data) structures that [HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata) can return for a specified type of HID report and a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the report type.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

If successful, **HidP_MaxDataListLength** returns the maximum number of [HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data) structures that [HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata) might return for a specified type of HID report and a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections). Otherwise, the routine returns zero, which indicates that either the report type or the preparsed data is not valid.

## Remarks

User-mode applications or kernel-mode drivers call **HidP_MaxDataListLength** to determine the maximum number of [HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data) structures that **HidP_GetData** can return.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_data)

[HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata)

[HidP_SetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setdata)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)