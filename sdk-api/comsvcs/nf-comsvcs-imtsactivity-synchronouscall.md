# IMTSActivity::SynchronousCall

## Description

Performs the user-defined work synchronously.

## Parameters

### `pCall` [in]

A pointer to the [IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall) interface that is used to implement the batch work.

## Return value

This method always returns the **HRESULT** returned by the [OnCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imtscall-oncall) method of the [IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall) interface.

## Remarks

The batch work that is run using this method runs in the context and thread apartment of the activity that was created by the call to [MTSCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-mtscreateactivity).

## See also

[IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity)