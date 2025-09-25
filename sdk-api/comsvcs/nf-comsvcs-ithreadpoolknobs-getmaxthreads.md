# IThreadPoolKnobs::GetMaxThreads

## Description

Retrieves the maximum number of threads that are allowed in the pool.

## Parameters

### `plcMaxThreads` [out]

The maximum number of threads allowed in the pool. A zero value indicates that the pool can grow without limit.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IThreadPoolKnobs](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ithreadpoolknobs)