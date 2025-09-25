# MFGetWorkQueueMMCSSPriority function

## Description

Gets the relative thread priority of a work queue.

## Parameters

### `dwWorkQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function. For platform work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers).

### `lPriority` [out]

Receives the relative thread priority.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function returns the relative thread priority set by the [MFBeginRegisterWorkQueueWithMMCSSEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginregisterworkqueuewithmmcssex) function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)