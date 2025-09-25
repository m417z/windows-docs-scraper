# IServiceActivity::SynchronousCall

## Description

Performs the user-defined work synchronously.

## Parameters

### `pIServiceCall` [in]

A pointer to the [IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall) interface that is used to implement the batch work.

## Return value

This method always returns the **HRESULT** value returned by the [OnCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicecall-oncall) method of the [IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall) interface.

## Remarks

The batch work that is run via this method runs in the context and thread apartment of the activity created by the call to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity).

## See also

[IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity)