# IServiceActivity::AsynchronousCall

## Description

Performs the user-defined work asynchronously.

## Parameters

### `pIServiceCall` [in]

A pointer to the [IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall) interface that is used to implement the batch work.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The batch work was accepted by the activity to run asynchronously. This return value does not necessarily mean that the batch work successfully completed. |
| **CO_E_ASYNC_WORK_REJECTED** | The batch work cannot be added to the asynchronous work queue of the activity. |

## Remarks

The batch work that is run by this method runs in the context and thread apartment of the activity that was created by the call to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity).

## See also

[IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity)