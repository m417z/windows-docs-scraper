# _HIDP_BUTTON_CAPS structure

## Description

The **HIDP_BUTTON_CAPS** structure contains information about the capability of a HID control button [usage](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) (or a set of buttons associated with a [usage range](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages)).

## Members

### `UsagePage`

Specifies the [usage page](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) for a usage or usage range.

### `ReportID`

Specifies the report ID of the HID report that contains the usage or usage range.

### `IsAlias`

Indicates, if **TRUE**, that a button has a set of [aliased usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages). Otherwise, if **IsAlias** is **FALSE**, the button has only one usage.

### `BitField`

Contains the data fields (one or two bytes) associated with an input, output, or feature main item.

### `LinkCollection`

Specifies the index of the [link collection](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) in a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [link collection array](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections) that contains the usage or usage range. If **LinkCollection** is zero, the usage or usage range is contained in the top-level collection.

### `LinkUsage`

Specifies the usage of the link collection that contains the usage or usage range. If **LinkCollection** is zero, **LinkUsage** specifies the usage of the top-level collection.

### `LinkUsagePage`

Specifies the usage page of the link collection that contains the usage or usage range. If **LinkCollection** is zero, **LinkUsagePage** specifies the usage page of the top-level collection.

### `IsRange`

Specifies, if **TRUE**, that the structure describes a usage range. Otherwise, if **IsRange** is **FALSE**, the structure describes a single usage.

### `IsStringRange`

Specifies, if **TRUE**, that the usage or usage range has a set of string descriptors. Otherwise, if **IsStringRange** is **FALSE**, the usage or usage range has zero or one string descriptor.

### `IsDesignatorRange`

Specifies, if **TRUE**, that the usage or usage range has a set of designators. Otherwise, if **IsDesignatorRange** is **FALSE**, the usage or usage range has zero or one designator.

### `IsAbsolute`

Specifies, if **TRUE**, that the button usage or usage range provides absolute data. Otherwise, if **IsAbsolute** is **FALSE**, the button data is the change in state from the previous value.

### `ReportCount`

HID defined report count. Available starting with API version 2.0. Call the [HidP_GetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getversion) function to get the API version.

### `Reserved2`

Reserved for internal system use.

### `Reserved`

Reserved for internal system use.

### `Range`

Specifies, if **IsRange** is **TRUE**, information about a usage range. Otherwise, if **IsRange** is **FALSE**, **NotRange** contains information about a single usage.

### `Range.UsageMin`

Indicates the inclusive lower bound of usage range whose inclusive upper bound is specified by **Range.UsageMax**.

### `Range.UsageMax`

Indicates the inclusive upper bound of a usage range whose inclusive lower bound is indicated by **Range.UsageMin**.

### `Range.StringMin`

Indicates the inclusive lower bound of a range of string descriptors (specified by string minimum and string maximum items) whose inclusive upper bound is indicated by **Range.StringMax**.

### `Range.StringMax`

Indicates the inclusive upper bound of a range of string descriptors (specified by string minimum and string maximum items) whose inclusive lower bound is indicated by **Range.StringMin**.

### `Range.DesignatorMin`

Indicates the inclusive lower bound of a range of designators (specified by designator minimum and designator maximum items) whose inclusive lower bound is indicated by **Range.DesignatorMax**.

### `Range.DesignatorMax`

Indicates the inclusive upper bound of a range of designators (specified by designator minimum and designator maximum items) whose inclusive lower bound is indicated by **Range.DesignatorMin**.

### `Range.DataIndexMin`

Indicates the inclusive lower bound of a sequential range of [data indices](https://learn.microsoft.com/windows-hardware/drivers/hid/data-indices) that correspond, one-to-one and in the same order, to the usages specified by the usage range **Range.UsageMin** to **Range.UsageMax**.

### `Range.DataIndexMax`

Indicates the inclusive upper bound of a sequential range of data indices that correspond, one-to-one and in the same order, to the usages specified by the usage range **Range.UsageMin** to **Range.UsageMax**.

### `NotRange`

Specifies, if **IsRange** is **FALSE**, information about a single usage. Otherwise, if **IsRange** is **TRUE**, **Range** contains information about a usage range.

### `NotRange.Reserved1`

Reserved for internal system use.

### `NotRange.Usage`

Indicates a [usage ID](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

### `NotRange.StringIndex`

Indicates a string descriptor ID for the usage specified by **NotRange.Usage**.

### `NotRange.Reserved2`

Reserved for internal system use.

### `NotRange.DesignatorIndex`

Indicates a designator ID for the usage specified by **NotRange.Usage**.

### `NotRange.Reserved3`

Reserved for internal system use.

### `NotRange.DataIndex`

Indicates the data index of the usage specified by **NotRange.Usage**.

### `NotRange.Reserved4`

Reserved for internal system use.

## Remarks

Clients obtain a [button capability array](https://learn.microsoft.com/windows-hardware/drivers/hid/button-capability-arrays) by calling [HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps) or [HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps). These routines return an array of HIDP_BUTTON_CAPS structures in a caller-allocated buffer. The required buffer length is specified in the [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure returned by [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps).

For information about the capabilities of HID control values, see [Collection Capability](https://learn.microsoft.com/windows-hardware/drivers/hid/collection-capability) and [Value Capability Arrays](https://learn.microsoft.com/windows-hardware/drivers/hid/value-capability-arrays).

When a report descriptor declares an input, output, or feature main item with fewer usage declarations than the *ReportCount*, then the last usage applies to all remaining unspecified count in that main item. As an example, you might have data that required many fields to describe, possibly buffered bytes. In this case, only one value cap structure is allocated for these associated fields, all with the same usage, and *ReportCount* reflects the number of fields involved. Normally *ReportCount* is one. To access all of the fields in such a value structure would require using [HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray) and [HidP_SetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevaluearray). The [HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue) and [HidP_SetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setscaledusagevalue) functions will also work. However, these functions only work with the first field of the structure.

## See also

- [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)
- [HIDP_VALUE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_value_caps)
- [HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps)
- [HidP_GetSpecificValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificvaluecaps)
- [HidP_GetValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getvaluecaps)