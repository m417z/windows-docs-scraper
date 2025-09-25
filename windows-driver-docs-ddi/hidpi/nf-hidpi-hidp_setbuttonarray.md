## Description

The **HidP_SetButtonArray** function sets the state of buttons via an array of [HIDP_BUTTON_ARRAY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-hidp_button_array_data) structures.

## Parameters

### `ReportType`

A value of either **HidP_Output** or **HidP_Feature** from the [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enum.

### `UsagePage`

The usage page to which the given usage refers.

### `LinkCollection`

(Optional) This value can be used to differentiate between two fields that may have the same *UsagePage* and Usage but exist in different collections. If the value is HIDP_LINK_COLLECTION_UNSPECIFIED, the first found button array matching the *UsagePage* and *Usage* will be returned, regardless of location. If the value is HIDP_LINK_COLLECTION_ROOT, the first found button array, in the root collection, matching the *UsagePage* and *Usage* will be returned.

### `Usage`

The usage whose button array **HidP_SetButtonArray** will set.

### `ButtonData`

The buffer with the values to set into the button array.

### `ButtonDataLength`

Number of elements in the *ButtonData* buffer.

### `PreparsedData`

The parsed data returned from [HIDCLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/).

### `Report`

The report packet. The first byte *must* be the *ReportId*.

### `ReportLength`

Length of the given report packet in bytes.

## Return value

**HidP_SetButtonArray** returns one of the following status values:

| Return code | Description |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
| HIDP_STATUS_SUCCESS | The button array in the report packet was set successfully |
| HIDP_STATUS_INVALID_REPORT_TYPE | *ReportType* is not valid |
| HIDP_STATUS_INVALID_PREPARSED_DATA | *PreparsedData* is not valid |
| HIDP_STATUS_INVALID_REPORT_LENGTH | The length of the report packet is not equal to the length specified in the **HIDP_CAPS** structure for the given *ReportType* |
| HIDP_STATUS_REPORT_DOES_NOT_EXIST | There are no reports on this device for the given *ReportType* |
| HIDP_STATUS_NOT_BUTTON_ARRAY | The control specified is not a button array |
| HIDP_STATUS_INCOMPATIBLE_REPORT_ID | The specified usage page, usage, and link collection exists in a report with a different report ID than the report being passed in |
| HIDP_STATUS_USAGE_NOT_FOUND | The usage page, usage, and link collection combination does not exist in any reports for this *ReportType* |
| HIDP_STATUS_DATA_INDEX_OUT_OF_RANGE | The *ArrayIndex* for one of the supplied **HIDP_BUTTON_ARRAY_DATA** structures is outside the valid range for this button array |

## Remarks

**HidP_SetButtonArray** sets the state of buttons for the first button array found, within the specified *LinkCollection*, with the supplied *Usage* for the specified *Report*.

The caller should use [HidP_GetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getversion) to determine if this function is available. **HidP_SetButtonArray** is only available if **HidP_GetVersion** returns a value of two or greater. Version two of the API corresponds to Windows 11.

A button array occurs when the last usage in the sequence of usages describing a main item, must be repeated because there are less usages defined than the *ReportCount* declared for the given main item. In this case, a single [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps) is allocated for that usage and the *ReportCount* of the **HIDP_BUTTON_CAPS** is set to reflect the number of fields the usage refers.

A **HIDP_BUTTON_CAPS** that describes a button array, will always have *ReportCount* greater than one. If *ReportCount* equals one, then it is not a button array and cannot be used with **HidP_SetButtonArray**. For more information, see [HidP_SetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages).

## See also

- [HidP_GetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getversion)
- [HidP_GetButtonArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttonarray)
- [HIDP_BUTTON_ARRAY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-hidp_button_array_data)
- [HIDP_LINK_COLLECTION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_link_collection_node)
- [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)
- [HidP_SetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages)