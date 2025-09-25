# MFLockWorkQueue function

## Description

Locks a work queue.

## Parameters

### `dwWorkQueue` [in]

The identifier for the work queue. The identifier is returned by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function prevents the [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function from shutting down the work queue. Use this function to ensure that asynchronous operations on the work queue complete gracefully before the platform shuts down. The **MFShutdown** function blocks until the work queue is unlocked, or until a fixed wait period has elapsed. (The wait period is a few seconds.)

Call [MFUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockworkqueue) to unlock the work queue. Each call to **MFLockWorkQueue** must be matched by a corresponding call to **MFUnlockWorkQueue**.

**Note** The [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function implicitly locks the work queue that it creates.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)