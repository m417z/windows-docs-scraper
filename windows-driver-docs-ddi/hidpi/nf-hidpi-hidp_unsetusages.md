# HidP_UnsetUsages function

## Description

The **HidP_UnsetUsages** routine sets specified HID control button [usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) OFF (zero) in a HID report.

## Parameters

### `ReportType` [in]

Specifies a [HIDP_REPORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ne-hidpi-_hidp_report_type) enumerator value that indicates the type of report located at *Report*.

### `UsagePage` [in]

Specifies the usage page of the usages specified by *UsageList*.

### `LinkCollection` [in, optional]

Specifies the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usages. If *LinkCollection* is nonzero, the routine only sets the usages, if they exist, in this link collection. If *LinkCollection* is zero, the routine sets the first usage for each usage it finds in the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) associated with *PreparsedData*.

### `UsageList` [in, out]

Pointer to the array of usages to set to OFF.

### `UsageLength` [in, out]

Specifies, on input, the number of usages in *UsageList*. See the Remarks section for information about the output value.

### `PreparsedData` [in]

Pointer to the [preparsed data](https://learn.microsoft.com/windows-hardware/drivers/hid/preparsed-data) of the top-level collection associated with the report located at *Report*.

### `Report` [in]

Pointer to a report.

### `ReportLength` [in]

Specifies the size, in bytes, of the report located at *Report*, which must be equal to the report length for the specified report type that [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) returns in a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

## Return value

**HidP_UnsetUsages** returns HIDP_STATUS_SUCCESS if it successfully sets to OFF all the usages in *UsageList*.

**HidP_UnsetUsages** returns one of the following status values if one of the input parameters is not valid:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data specified by *PreparsedData* is not valid. |
| **HIDP_STATUS_INVALID_REPORT_LENGTH** | The report length is not valid. |
| **HIDP_STATUS_INVALID_REPORT_TYPE** | The report type is not valid. |
| **HIDP_STATUS_REPORT_DOES_NOT_EXIST** | The collection does not contain a report of the specified type. |

**HidP_UnsetUsages** returns one of the following status values if it was not able to set to OFF one of the usages in *UsageList*:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_BUTTON_NOT_PRESSED** | A usage is already set to OFF. |
| **HIDP_STATUS_INCOMPATIBLE_REPORT_ID** | A usage is not contained in the specified report, but is contained in another report of the specified type. |
| **HIDP_STATUS_USAGE_NOT_FOUND** | The routine did not find a usage in any report of the specified type. |

## Remarks

**HidP_UnsetUsages** sets *UsageLength* as follows:

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidP_SetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[HidP_SetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setdata)

[HidP_SetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages)

[HidP_UnsetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)