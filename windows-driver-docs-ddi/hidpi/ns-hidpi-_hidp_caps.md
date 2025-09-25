# _HIDP_CAPS structure

## Description

The HIDP_CAPS structure contains information about a top-level [collection's capability](https://learn.microsoft.com/windows-hardware/drivers/hid/collection-capability).

## Members

### `Usage`

Specifies a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

### `UsagePage`

Specifies the top-level collection's [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

### `InputReportByteLength`

Specifies the maximum size, in bytes, of all the input reports. Includes the report ID, which is prepended to the report data. If report ID is not used, the ID value is zero.

### `OutputReportByteLength`

Specifies the maximum size, in bytes, of all the output reports. Includes the report ID, which is prepended to the report data. If report ID is not used, the ID value is zero.

### `FeatureReportByteLength`

Specifies the maximum length, in bytes, of all the feature reports. Includes the report ID, which is prepended to the report data. If report ID is not used, the ID value is zero.

### `Reserved`

Reserved for internal system use.

### `NumberLinkCollectionNodes`

Specifies the number of [HIDP_LINK_COLLECTION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_link_collection_node) structures that are returned for this top-level collection by [HidP_GetLinkCollectionNodes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getlinkcollectionnodes).

### `NumberInputButtonCaps`

Specifies the number of input [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps) structures that [HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps) returns.

### `NumberInputValueCaps`

Specifies the number of input [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps) structures that [HidP_GetValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getvaluecaps) returns.

### `NumberInputDataIndices`

Specifies the number of [data indices](https://learn.microsoft.com/windows-hardware/drivers/hid/data-indices) assigned to buttons and values in all input reports.

### `NumberOutputButtonCaps`

Specifies the number of output HIDP_BUTTON_CAPS structures that **HidP_GetButtonCaps** returns.

### `NumberOutputValueCaps`

Specifies the number of output HIDP_VALUE_CAPS structures that **HidP_GetValueCaps** returns.

### `NumberOutputDataIndices`

Specifies the number of data indices assigned to buttons and values in all output reports.

### `NumberFeatureButtonCaps`

Specifies the total number of feature HIDP_BUTTONS_CAPS structures that **HidP_GetButtonCaps** returns.

### `NumberFeatureValueCaps`

Specifies the total number of feature HIDP_VALUE_CAPS structures that **HidP_GetValueCaps** returns.

### `NumberFeatureDataIndices`

Specifies the number of data indices assigned to buttons and values in all feature reports.

## Remarks

Callers of the [HIDClass support routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/) use the information provided in this structure when a called routine requires, as input, the size of a report type, the number of link collection nodes, the number of control capabilities, or the number of data indices.

## See also

- [HIDP_BUTTON_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_button_caps)
- [HIDP_LINK_COLLECTION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_link_collection_node)
- [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)
- [HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [HidP_GetLinkCollectionNodes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getlinkcollectionnodes)
- [HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps)
- [HidP_GetSpecificValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificvaluecaps)
- [HidP_GetValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getvaluecaps)