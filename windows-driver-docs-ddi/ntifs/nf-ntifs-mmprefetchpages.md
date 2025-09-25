# MmPrefetchPages function

## Description

The **MmPrefetchPages** routine reads groups of pages from secondary storage in the optimal fashion.

## Parameters

### `NumberOfLists` [in]

The number of read-lists in the array passed in the *ReadLists* parameter.

### `ReadLists` [in]

A pointer to an array of read-lists to be prefetched.

## Return value

**MmPrefetchPages** returns STATUS_SUCCESS or an appropriate error status representing the final completion status of the operation. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_INSUFFICIENT_RESOURCES** | A temporary buffer required by this function could not be allocated. |
| **STATUS_INVALID_PARAMETER_1** | A section in *ReadLists* is not prefetchable (for example, a physical or pagefile-backed section), or an invalid *NumberOfLists* value was provided. |

**MmPrefetchPages** returns STATUS_SUCCESS on success and also if all of the requested pages were already in memory indicating no reads from secondary storage were required.

## Remarks

**MmPrefetchPages** reads pages from secondary storage described in the read-lists in the optimal fashion. The caller builds a list of various file objects and logical block offsets, passing them to the **MmPrefetchPages** function which examines the internal pages, reading in those that are not already valid or in transition. The pages are read with a single read, using a dummy page to bridge small gaps. If the gap is "large", then separate reads are issued.

> [!NOTE]
>
> The [section object](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views) must already exist for the file to be prefetched. A section handle can be obtained by calling [**ZwCreateSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile).