# HidP_GetSpecificButtonCaps function

## Description

The **HidP_GetSpecificButtonCaps** routine returns a [button capability array](https://learn.microsoft.com/windows-hardware/drivers/hid/button-capability-arrays) that describes all HID control buttons in a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) that meet a specified selection criteria.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UsagePage` [in]

Specifies a usage page as a search criteria. If *UsagePage* is nonzero, only buttons that specify this usage page are returned.

### `LinkCollection` [in]

Specifies a [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) as a search criteria. If *LinkCollection* is nonzero, only buttons that are part of this link collection are returned.

### `Usage` [in]

Specifies a [HID usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) as a search criteria. If *Usage* is nonzero, only buttons that specify this usage will be returned.

### `ButtonCaps` [out]

Pointer to a caller-allocated buffer in which the routine returns a button capability array for the specified report type.

### `ButtonCapsLength` [in, out]

Specifies the length on input, in array elements, of the buffer provided at *ButtonCaps*. On output, this parameter is set to the number of elements that the routine actually returned.

### `PreparsedData` [in]

Pointer to a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

**HidP_GetSpecificButtonCaps** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the capability data. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |

## Remarks

The required size of the *ButtonCaps* array is specified by the **Number***Xxx***ButtonCaps** members of a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

When calling **HidP_GetSpecificButtonCaps**, specifying zero for *UsagePage*, *Usage*, and *LinkCollection* is equivalent to calling **HidP_GetButtonCaps**.

For more information about a collection's capability, see [Obtaining Collection Information](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-collection-information).

See also [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)

[HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)