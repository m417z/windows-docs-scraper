## Description

**HidP_GetButtonArray** returns an array of [HIDP_BUTTON_ARRAY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-hidp_button_array_data) structures for the specified report.

## Parameters

### `ReportType`

A value from the [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enum.

### `UsagePage`

The usage page to which the given usage refers.

### `LinkCollection`

(Optional) This value can be used to differentiate between two fields that may have the same *UsagePage* and *Usage* but exist in different collections. If the *LinkCollection* value is **HIDP_LINK_COLLECTION_UNSPECIFIED**, the first button array found matching the *UsagePage* and *Usage* will be returned, regardless of location. If the *LinkCollection* value is **HIDP_LINK_COLLECTION_ROOT**, the first button array found in the root collection matching the *UsagePage* and *Usage* will be returned.

### `Usage`

The usage whose buttons **HidP_GetButtonArray** will retrieve.

### `ButtonData`

An array of **HIDP_BUTTON_ARRAY_DATA** structures where the data of buttons set to `ON` will be placed. The number of elements required is the *ReportCount* field of the [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps) for this control. This buffer is provided by the caller.

### `ButtonDataLength`

As input, this parameter specifies the length of the *ButtonData* parameter in number of array elements, not number of bytes. As output, if HIDP_STATUS_SUCCESS is returned, this value is set to indicate how many of those array elements were filled in by the function. The maximum number of **HIDP_BUTTON_ARRAY_DATA** structures that can be returned is determined by HIDP_BUTTON_CAPS.ReportCount. If HIDP_STATUS_BUFFER_TOO_SMALL is returned, this value contains the number of array elements needed to successfully complete the request.

### `PreparsedData`

The pre-parsed data returned by the [HIDCLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/).

### `Report`

The report packet. The first byte must be the *ReportId*. This will be correctly set if the report is read from the system.

### `ReportLength`

Length of the given report packet in bytes.

## Return value

**HidP_GetButtonArray** returns one of the following status values:

| Return code | Description |
|------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| HIDP_STATUS_SUCCESS | Successfully retrieved the buttons from the report packet |
| HIDP_STATUS_INVALID_REPORT_TYPE | The *ReportType* parameter is not valid |
| HIDP_STATUS_INVALID_PREPARSED_DATA | The *PreparsedData* parameter is not valid |
| HIDP_STATUS_INVALID_REPORT_LENGTH | The length of the report packet is not equal to the length specified in the **HIDP_CAPS** structure for the given *ReportType* |
| HIDP_STATUS_NOT_BUTTON_ARRAY | The control specified is not a button array |
| HIDP_STATUS_BUFFER_TOO_SMALL | The size of the passed in buffer in which to return the array is too small |
| HIDP_STATUS_INCOMPATIBLE_REPORT_ID | The specified usage page, usage and link collection exists in a report with a different report ID than the report being passed in |
| HIDP_STATUS_USAGE_NOT_FOUND | The usage page, usage, and link collection combination does not exist in any reports for this *ReportType* |

## Remarks

The caller should use [HidP_GetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getversion) to determine if this function is available. **HidP_GetButtonArray** is only available if **HidP_GetVersion** returns a value of two or greater. Version two of the API corresponds to Windows 11.

A button array occurs when the last usage in the sequence of usages describing a main item, must be repeated because there are less usages defined than the *ReportCount* declared for the given main item. In this case, a single **HIDP_BUTTON_CAPS** is allocated for that usage and the *ReportCount* of the **HIDP_BUTTON_CAPS** is set to reflect the number of fields to which the usage refers.

A **HIDP_BUTTON_CAPS** that describes a button array will always have *ReportCount* greater than one. If *ReportCount* equals one, then it is not a button array and cannot be used with **HidP_GetButtonArray**. See [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) instead.

## See also

- [HidP_GetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getversion)
- [HIDP_BUTTON_ARRAY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-hidp_button_array_data)
- [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type)
- [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)
- [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)
- [HidP_SetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setbuttonarray)