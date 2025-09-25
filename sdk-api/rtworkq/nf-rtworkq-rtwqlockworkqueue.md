# RtwqLockWorkQueue function

## Description

Locks a work queue.

## Parameters

### `workQueueId` [in]

The identifier for the work queue. The identifier is returned by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.