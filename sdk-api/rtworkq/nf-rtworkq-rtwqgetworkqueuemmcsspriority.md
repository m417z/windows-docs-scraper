# RtwqGetWorkQueueMMCSSPriority function

## Description

Gets the relative thread priority of a work queue.

## Parameters

### `workQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `priority` [out]

Receives the relative thread priority.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function returns the relative thread priority set by the [RtwqBeginRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqbeginregisterworkqueuewithmmcss) function.