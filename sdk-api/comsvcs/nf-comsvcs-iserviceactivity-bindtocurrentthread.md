# IServiceActivity::BindToCurrentThread

## Description

Binds the user-defined batch work to the current thread.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

This method binds the batch work that is submitted via the AsynchronousCall or the SynchronousCall method to the current single-threaded apartment (STA). It has no effect if the current thread is being run in the multithreaded apartment (MTA). The current thread model is determined by the configuration of the [IServiceThreadPoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicethreadpoolconfig) interface of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that is passed via the *pIUnknown* parameter during the call to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity).

Calling this method is equivalent to having called [IServiceThreadPoolConfig::SetBindingInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicethreadpoolconfig-setbindinginfo) with CSC_BindToPoolThread on the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that was passed through the *pIUnknown* parameter to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity). However, after the activity has been created by **CoCreateActivity**, you can no longer call **IServiceThreadPoolConfig::SetBindingInfo** to change the thread binding. To change the thread binding after the activity has been created, you must call the **BindToCurrentThread** or the [UnbindFromThread](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-unbindfromthread) method of [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity).

## See also

[IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity)