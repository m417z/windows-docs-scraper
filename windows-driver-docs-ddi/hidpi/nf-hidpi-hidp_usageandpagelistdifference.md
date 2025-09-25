# HidP_UsageAndPageListDifference function

## Description

The **HidP_UsageAndPageListDifference** function returns the difference between two lists of usages, as might be returned from [**HidP_GetUsages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages). In other words, it returns a list of usages that are in the current list but not the previous list as well as a list of usages that are in the previous list but not the current list.

## Parameters

### `PreviousUsageList` [in, reads]

The list of usages before.

### `CurrentUsageList` [in, reads]

The list of usages now.

### `BreakUsageList` [out, writes]

*PreviousUsageList* minus *CurrentUsageList*

### `MakeUsageList` [out, writes]

*CurrentUsageList* minus *PreviousUsageList*

### `UsageListLength` [in]

Represents the length of the usage lists in array elements. If comparing two lists with a differing number of array elements, this value is the size of the larger of the two lists. Any zero found with a list indicates an early termination of the list and any usages found after the first zero are ignored.

## Return value

**HidP_UsageAndPageListDifference** returns HIDP_STATUS_SUCCESS if the call was successful. Otherwise, it returns an [**NTSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.