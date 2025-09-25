# IMTSActivity::BindToCurrentThread

## Description

Binds the batch work that is submitted using [IMTSActivity::AsyncCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-asynccall) or [IMTSActivity::SynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-synchronouscall) to the current single-threaded apartment (STA).

This method is designed to be called from the implementation of the [IMTSCall::OnCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtscall-oncall) method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity)