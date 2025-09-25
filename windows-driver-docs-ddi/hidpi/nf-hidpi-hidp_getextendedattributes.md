# HidP_GetExtendedAttributes function

## Description

The **HidP_GetExtendedAttributes** routine returns the extended attributes of a HID control.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of HID report associated with the HID control specified by *DataIndex*.

### `DataIndex` [in]

Specifies the [data index](https://learn.microsoft.com/windows-hardware/drivers/hid/data-indices) of the HID control.

### `PreparsedData` [in]

Specifies the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) for the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) that contains the specified control.

### `Attributes` [out]

Pointer to a caller-allocated buffer that the routine uses to return the extended attributes of the control specified by *DataIndex*.

### `LengthAttributes` [in, out]

Specifies the size, in bytes, of the *Attributes* buffer (which must be greater than or equal to sizeof(HIDP_EXTENDED_ATTRIBUTES).

## Return value

**HidP_GetExtendedAttributes** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned all the control's extended attribute information. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | The *Attribute* buffer was not large enough to hold all the extended attribute information. |
| **HIDP_STATUS_DATA_INDEX_NOT_FOUND** | The specified data index is not valid. |

## Remarks

**HidP_GetExtendedAttributes** returns a variable length [HIDP_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_extended_attributes) structure in the *Attribute* buffer. The extended attributes structure contains, in consecutive order, the fixed length members (**NumGlobalUnknowns**, **Reserved**, and **GlobalUnknowns**) followed by a variable length array of [HIDP_UNKNOWN_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_unknown_token) structures. The first member of the unknown token array is located at (PHIDP_UNKNOWN_TOKEN*)&(*Attributes*->**Data**).

The routine returns as many bytes of the extended attribute information as the *Attribute* buffer can hold. If the buffer is too small, the routine truncates the information it returns. To determine the number of unknown tokens in the variable length array, a caller can first use the *Attributes* buffer to return the value of the **NumGlobalUnknowns** member of the extended attributes information.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_extended_attributes)

[HIDP_UNKNOWN_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_unknown_token)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)