# RtwqUnlockWorkQueue function

## Description

Unlocks a work queue.

## Parameters

### `workQueueId` [in]

Identifier for the work queue to be unlocked. This identifier is returned by the [RtwqAllocateSerialWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateserialworkqueue), [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue), or [RtwqLockSharedWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqlocksharedworkqueue) functions.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.