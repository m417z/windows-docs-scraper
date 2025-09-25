# IServiceThreadPoolConfig::SelectThreadPool

## Description

Selects the thread pool in which the work submitted through the activity is to run.

## Parameters

### `threadPool` [in]

A value from the [CSC_ThreadPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_threadpool) enumeration.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[IServiceThreadPoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicethreadpoolconfig)