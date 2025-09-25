# IServiceCall::OnCall

## Description

Triggers the execution of the batch work implemented in this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

The batch work that is run in this method runs in the context and thread apartment of the activity that was created by the call to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity). The batch work in this method is run through a call to either [SynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-synchronouscall) or [AsynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-asynchronouscall), using the [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity) pointer that was returned from the call to **CoCreateActivity**.

You must make sure that this method is thread safe in situations where the activity object that is created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) is not created with a synchronized context because in such situations many calls to **OnCall** can run at the same time.

To achieve the best performance from the system, the context configuration of the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) should be matched to the batch work performed by the **OnCall** method. For example, if the batch work in the **OnCall** method uses poolable objects, the activity created by **CoCreateActivity** should be configured to use the multithreaded apartment (MTA).

## See also

[IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall)