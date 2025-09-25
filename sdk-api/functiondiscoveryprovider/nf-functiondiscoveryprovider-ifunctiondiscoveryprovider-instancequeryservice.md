# IFunctionDiscoveryProvider::InstanceQueryService

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a provider-specific COM object for the function instance. Provider writers can implement this method to offer additional functionality through the COM object.

## Parameters

### `pIFunctionInstance` [in]

A pointer to the [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `guidService` [in]

The unique identifier of the service (a SID). This is the service ID defined by the provider writer. For an example, see FunctionDiscoveryServiceIDs.h.

### `riid` [in]

The unique identifier of the interface the caller wishes to receive for the service.

### `ppIUnknown` [out]

A pointer that receives the interface pointer of the service. The caller is responsible for calling **Release** through this interface pointer when the service is no longer needed.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOINTERFACE** | The provider does implement the service identified by *guidService* but does not implement the interface identified by *rrid*. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **E_NOTIMPL** | The provider does not implement the [IFunctionInstance::QueryService](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364381(v=vs.85)) method, or the service identifier specified by *guidService* does not match the provider's service identifier. |

## Remarks

**InstanceQueryService** creates or accesses the implementation the service identified with *guidService*, returning the address of the interface specified by *riid* in the *ppv* argument. Providers can implement the service and this method provides a mechanism for the provider to supply this implementation rather then requiring the creation of a new object to implement the service.

The provider should return **E_NOINTERFACE** if the *guidService* does not belong to this provider, or the *riid* interface is not supported. The provider should return **E_NOTIMPL** if it simply does not implement this method or does not implement the requested SID.

Any provider that supports embedded services or devices must implement the SID_PNPXServiceCollection service. If the SID_PNPXServiceCollection service is supported, the client can call [IFunctionInstance::QueryService](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364381(v=vs.85)) to access the information and metadata associated with the embedded services or devices. For example, the PnP-X providers (that is, the [SSDP provider](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/ssdp-provider) and the WSD provider) implement support for the SID_PNPXServiceCollection service. Not all providers implement SID_PNPXServiceCollection service support.

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)