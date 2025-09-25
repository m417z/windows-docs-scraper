# IServiceActivity::UnbindFromThread

## Description

Unbinds the user-defined batch work from the thread on which it is running.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

This method unbinds the batch work that is submitted through the [AsynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-asynchronouscall) or the [SynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-synchronouscall) method from the thread it is running on. It has no effect if the batch work was not previously bound to a thread.

Calling this method is equivalent to having called [IServiceThreadPoolConfig::SetBindingInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicethreadpoolconfig-setbindinginfo) with CSC_NoBinding on the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that was passed through the *pIUnknown* parameter to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity). However, after the activity has been created by **CoCreateActivity**, you can no longer call **IServiceThreadPoolConfig::SetBindingInfo** to change the thread binding. To change the thread binding after the activity has been created, you must call the [BindToCurrentThread](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-bindtocurrentthread) or the **UnbindFromThread** method of [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity).

## See also

[IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity)