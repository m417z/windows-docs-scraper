# IMTSActivity::AsyncCall

## Description

Performs the user-defined work asynchronously.

## Parameters

### `pCall` [in]

A pointer to the [IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall) interface that is used to implement the batch work.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The batch work that is run using this method runs in the context and thread apartment of the activity that was created by the call to [MTSCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-mtscreateactivity).

A return value of S_OK indicates that the batch work was accepted by the activity to run asynchronously. However, it does not necessarily mean that the batch work successfully completed.

## See also

[IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity)