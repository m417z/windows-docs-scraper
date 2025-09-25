# HidP_GetSpecificValueCaps function

## Description

The **HidP_GetSpecificValueCaps** routine returns a [value capability array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays) that describes all HID control values that meet a specified selection criteria.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `UsagePage` [in]

Specifies a usage page as a search criteria. If *UsagePage* is nonzero, only values that specify this usage page are returned.

### `LinkCollection` [in]

Specifies a [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) as a search criteria. If *LinkCollection* is nonzero, only values that are part of this link collection are returned.

### `Usage` [in]

Specifies a [HID usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) as a search criteria. If *Usage* is nonzero, only values that specify this usage will be returned.

### `ValueCaps` [out]

Pointer to a caller-allocated buffer in which the routine returns a value capability array for the specified report type.

### `ValueCapsLength` [in, out]

Specifies the length on input, in array elements, of the buffer provided at *ValueCaps*. On output, this parameter is set to the number of elements that routine actually returns.

### `PreparsedData` [in]

Pointer to a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

**HidP_GetSpecificValueCaps** returns one of the following status values:

| Return code | NT Status Value | Description |
| --- | --- | --- |
| **HIDP_STATUS_SUCCESS** | **0x00110000** | The routine successfully returned the capability data. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | **0xc0110001** | The preparsed data is not valid. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | **0xc0110004** | The usage does not exist in any report of the specified report type. |

## Remarks

The required size of the *ValueCaps* buffer is specified by the **Number***Xxx***ValueCaps** members of a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

When calling **HidP_GetSpecificValueCaps**, specifying zero for *UsagePage*, *Usage*, and *LinkCollection* is equivalent to calling **HidP_GetValueCaps**.

For more information about a collection's capability, see [Obtaining Collection Information](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-collection-information).

See also [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)

[HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[HidP_GetValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getvaluecaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)