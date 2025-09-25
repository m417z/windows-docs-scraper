# CoCreateActivity function

## Description

Creates an activity to do synchronous or asynchronous batch work that can use COM+ services without needing to create a COM+ component.

## Parameters

### `pIUnknown` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object, created from the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) class, that contains the configuration information for the services to be used within the activity created by **CoCreateActivity**.

### `riid` [in]

The ID of the interface to be returned through the *ppObj* parameter. This parameter should always be IID_IServiceActivity so that a pointer to [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity) is returned.

### `ppObj` [out]

A pointer to the interface of an activity object. The activity object is automatically created by the call to **CoCreateActivity**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_SXS_CONFIG** | The side-by-side assembly configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. |
| **CO_E_THREADPOOL_CONFIG** | The thread pool configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. |
| **CO_E_TRACKER_CONFIG** | The tracker configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. |
| **COMADMIN_E_PARTITION_ACCESSDENIED** | The caller does not have access permissions for the COM+ partition. |

## Remarks

**CoCreateActivity** creates an activity object that is used to submit batch work to the COM+ system. The context associated with the activity is completely determined by the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that is passed through the *pIUnknown* parameter.

**CoCreateActivity** enables applications to use COM+ services in their batch work without needing to create a component to use those services. In addition to reducing overhead by not requiring the creation of a component, using **CoCreateActivity** provides for a more efficient runtime environment because it allows the environment to support application-wide service configuration without needing to access information that is stored in the COM+ registration database (RegDB).

The batch work that is submitted through **CoCreateActivity** can be either synchronous or asynchronous and can run in either a single-threaded apartment (STA) or the multithreaded apartment (MTA). The threading model that is used is determined by the [IServiceThreadPoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicethreadpoolconfig) interface of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that is passed through the *pIUnknown* parameter.

**CoCreateActivity** returns a pointer to the [IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity) interface of the object that is created by the call to **CoCreateActivity**. By using the methods of **IServiceActivity**, you determine whether the batch work is done synchronously or asynchronously. The batch work itself is implemented through the [IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall) interface.

## See also

[COM+ Services Without Components](https://learn.microsoft.com/windows/desktop/cossdk/com--services-without-components)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain)

[IServiceActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iserviceactivity)

[IServiceCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicecall)