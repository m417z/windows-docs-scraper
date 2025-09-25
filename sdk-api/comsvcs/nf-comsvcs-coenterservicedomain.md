# CoEnterServiceDomain function

## Description

Used to enter code that can then use COM+ services.

## Parameters

### `pConfigObject` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object, created from the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) class, that contains the configuration information for the services to be used within the enclosed code.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_SXS_CONFIG** | The side-by-side assembly configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. |
| **CO_E_THREADPOOL_CONFIG** | The thread pool configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. The thread apartment model cannot be reconfigured by calling [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain). |
| **CO_E_TRACKER_CONFIG** | The tracker configuration of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object is invalid. |
| **COMADMIN_E_PARTITION_ACCESSDENIED** | The caller does not have access permissions for the COM+ partition. |

## Remarks

Code that is enclosed between calls to **CoEnterServiceDomain** and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain) runs in its own context and behaves as though it were a method that is called on an object created within the context. **CoEnterServiceDomain** cannot switch to a different apartment model, so the enclosed code runs in the caller's apartment and on the caller's thread. It is an error to try to change the apartment model through the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object when calling **CoEnterServiceDomain**.

**CoEnterServiceDomain** first creates a context that is configured as specified by the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that is passed as the *pConfigObject* parameter. Policies on both the client and server sides are then triggered as if a method call had occurred. The new context is then pushed onto a context stack and becomes the current context.

Because of their efficient design and because no thread marshaling is involved, using **CoEnterServiceDomain** and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain) involves significantly reduced overhead as compared to an equivalent method call.

**CoEnterServiceDomain** and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain) are particularly useful in applications, which can use these functions to access COM+ services without needing to create a component to do so.

The **CoEnterServiceDomain** and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain) pairs can be nested.

## See also

[COM+ Services Without Components](https://learn.microsoft.com/windows/desktop/cossdk/com--services-without-components)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain)