# IThreadPoolKnobs::GetMaxQueuedRequests

## Description

Retrieves the maximum number of asynchronous execution requests that can be simultaneously queued.

## Parameters

### `plcMaxQueuedRequests` [out]

The maximum number of asynchronous execution requests that can be simultaneously queued. A zero value indicates that the queue can grow without limit.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IThreadPoolKnobs](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ithreadpoolknobs)