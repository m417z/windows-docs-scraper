# GetDebuggerCacheSize function

## Description

The **GetDebuggerCacheSize** function returns the size of the cache that is used by the debugger to hold data that was obtained from the target.

## Parameters

### `CacheSize` [out]

Receives the size of the debugger's cache.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

The size of the cache can be set and retrieved by using the [.cache](https://learn.microsoft.com/windows-hardware/drivers/debugger/-cache--set-cache-size-) command.

Each target process has its own cache. The returned size is the size of the cache for the current target.

## See also

[.cache (Set Cache Size)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-cache--set-cache-size-)