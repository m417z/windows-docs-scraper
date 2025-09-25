# IMTSCall::OnCall

## Description

[[IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall) is available for use in the operating systems specified in the Requirements section. It may be altered of unavailable in subsequent versions. Instead, use [IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall).]

Triggers the execution of the batch work implemented in this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The batch work that is run in this method runs in the context and thread apartment of the activity that was created by the call to [MTSCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-mtscreateactivity). The batch work in this method is run using a call to either [IMTSActivity::SynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-synchronouscall) or [IMTSActivity::AsyncCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-asynccall), using the [IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity) pointer that was returned from the call to **MTSCreateActivity**.

## See also

[IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall)