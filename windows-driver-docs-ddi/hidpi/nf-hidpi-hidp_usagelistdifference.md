# HidP_UsageListDifference function

## Description

The **HidP_UsageListDifference** routine returns the differences between two arrays of [HID usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages).

## Parameters

### `PreviousUsageList` [in]

Pointer to a list of usages that the routine compares with the list of usages in *CurrentUsageList*.

### `CurrentUsageList` [in]

Pointer to a list of usages that the routine compares with the list of usages in *PreviousUsageList*.

### `BreakUsageList` [out]

Pointer to a caller-allocated buffer that, on return, contains a list of the usages that are in *PreviousUsageList*, but not in *CurrentUsageList*.

### `MakeUsageList` [out]

Pointer to a caller-allocated buffer that, on return, contains a list of the usages that are in *CurrentUsageList*, but not in *PreviousUsageList*.

### `UsageListLength` [in]

Specifies the length, in array elements, of the buffers provided at *CurrentUsageList* and *PreviousUsageList*.

## Return value

**HidP_UsageListDifference** returns HIDP_STATUS_SUCCESS.

## Remarks

A user-mode application or kernel-mode driver can use this routine to compare two usage lists, for example, to determine the change in button state between two usage lists returned by two [HidP_GetButtons](https://learn.microsoft.com/windows-hardware/drivers/hid/hdpi-h-macros) calls.

If the input usage lists have different lengths, an application or driver should set *UsageListLength* to the length of the larger list.

The routine interprets a zero usage in an input usage list as a delimiter that ends the list. Any usages after a zero in a list are not processed. Unused usages in an output list are set to zero.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidP_UsageAndPageListDifference](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_usageandpagelistdifference)