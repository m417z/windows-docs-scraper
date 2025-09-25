# HidP_GetValueCaps function

## Description

The **HidP_GetValueCaps** routine returns a [value capability array](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays) that describes all the HID control values in a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) for a specified type of HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that identifies the report type.

### `ValueCaps` [out]

Pointer to a caller-allocated buffer in which the routine returns a value capability array for the specified report type.

### `ValueCapsLength` [in, out]

Specifies the length, on input, in array elements, of the *ValueCaps* buffer. On output, the routine sets *ValueCapsLength* to the number of elements that the it actually returns.

### `PreparsedData` [in]

Pointer to a top-level collection's [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data).

## Return value

**HidP_GetValueCaps** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the capability data. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |

## Remarks

The correct length for *ValueCapsLength* is specified by the **Number***Xxx***ValueCaps** members of a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

For more information about a collection's capability, see [Obtaining Collection Information](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-collection-information).

See also [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)

[HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)

[HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)