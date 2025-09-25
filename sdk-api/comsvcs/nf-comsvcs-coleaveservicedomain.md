# CoLeaveServiceDomain function

## Description

Used to leave code that uses COM+ services.

## Parameters

### `pUnkStatus` [in]

If you want to know the status of the transaction that is completed by the call, this must be a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of an object that implements the [ITransactionStatus](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionstatus) interface. If the enclosed code did not use transactions or if you do not need to know the transaction status, this parameter should be **NULL**. This parameter is ignored if it is non-**NULL** and if no transactions were used in the service domain.

## Remarks

Code that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and **CoLeaveServiceDomain** runs in its own context and behaves as though it were a method that is called from an object created within the context.

**CoLeaveServiceDomain** triggers the server and then the client side policies as if a method call was returning. The current context is then popped from the context stack, and the context that was running when [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) was called becomes the current context.

Because of their efficient design and because no thread marshaling is involved, using [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and **CoLeaveServiceDomain** involves significantly reduced overhead as compared to an equivalent method call.

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and **CoLeaveServiceDomain** are particularly useful in applications, which can use these functions to access COM+ services without needing to create a component to do so.

The [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and **CoLeaveServiceDomain** pairs can be nested. It is up to the user to make sure that the pairs of calls are balanced so that every call to **CoLeaveServiceDomain** matches a previous call to **CoEnterServiceDomain**.

## See also

[COM+ Services Without Components](https://learn.microsoft.com/windows/desktop/cossdk/com--services-without-components)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)