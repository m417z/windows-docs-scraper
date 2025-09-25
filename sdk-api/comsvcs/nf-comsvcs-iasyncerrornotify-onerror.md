# IAsyncErrorNotify::OnError

## Description

Called by COM+ when an error occurs in your asynchronous batch work.

## Parameters

### `hr` [in]

The **HRESULT** value of the error that occurred while your batch work was running asynchronously.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

This method should be implemented to gracefully handle errors that occur when your batch work is running asynchronously. Because the process terminates (FailFast) on any unrecoverable error, without this method you have no way of knowing when errors occur in your asynchronous batch work. The process also terminates when this method returns an error as its return value.

The batch work itself is implemented in [IServiceCall::OnCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicecall-oncall), and it is run asynchronously by calling [IServiceActivity::AsynchronousCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceactivity-asynchronouscall) using the [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity) pointer that was returned from the call to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity).

## See also

[IAsyncErrorNotify](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iasyncerrornotify)