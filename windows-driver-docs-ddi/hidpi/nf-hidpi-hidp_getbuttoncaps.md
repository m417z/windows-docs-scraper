# HidP_GetButtonCaps function

## Description

The **HidP_GetButtonCaps** routine returns a [button capability array](https://learn.microsoft.com/windows-hardware/drivers/hid/button-capability-arrays) that describes all the HID control buttons in a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) for a specified type of HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `ButtonCaps` [out]

Pointer to a caller-allocated buffer that the routine uses to return a button capability array for the specified report type.

### `ButtonCapsLength` [in, out]

Specifies the length on input, in array elements, of the buffer provided at *ButtonCaps*. On output, this parameter is set to the actual number of elements that the routine returns.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

**HidP_GetButtonCaps** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the capability data. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |

## Remarks

**HidP_GetButtonCaps** returns the capability of all buttons in a top level collection for a specified report type.

*ButtonCapsLength* should be set to the value of the **Number***Xxx***ButtonCaps** member of the [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure returned by [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps), where *Xxx* specifies the report type.

To obtain a subset of button capabilities, selected by [usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages), [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages), or [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections), use [HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps).

For more information about a collection's capability, see [Obtaining Collection Information](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-collection-information).

See also [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)