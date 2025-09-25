# IThreadPoolKnobs::GetDeleteDelay

## Description

Retrieves the number of milliseconds a pooled thread can idle before being destroyed.

## Parameters

### `pmsecDeleteDelay` [out]

The number of milliseconds a pooled thread can idle before being destroyed. A zero value indicates that threads are never automatically deleted.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IThreadPoolKnobs](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ithreadpoolknobs)