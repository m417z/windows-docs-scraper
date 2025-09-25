# IMTSActivity::UnbindFromThread

## Description

Unbinds the batch work that is submitted using [IMTSActivity::AsyncCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-asynccall) or [IMTSActivity::SynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtsactivity-synchronouscall) from the thread on which it is running. It has no effect if the batch work was not previously bound to a thread.

This method is designed to be called from the implementation of the [IMTSCall::OnCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtscall-oncall) method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity)