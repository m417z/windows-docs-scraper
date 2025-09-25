# IWSDDeviceHost::AddDynamicService

## Description

Registers a service object for incoming requests, but does not add the service to the device host metadata. This is used for transient (dynamic) services.

## Parameters

### `pszServiceId` [in]

The ID for the dynamic service. The service ID must be distinct from all the service IDs in the service host metadata and from any other registered dynamic service. The *pszServiceId* must be a URI.

### `pszEndpointAddress` [in, optional]

An optional URI to use as the endpoint address for this service. If none is specified, the device host will assume the service should be available on all local transport addresses.

### `pPortType` [in, optional]

Reference to a [WSD_PORT_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_port_type) structure that specifies the port type.
May be **NULL**. Specify only one of *pPortType* and *pPortName*.

### `pPortName` [in, optional]

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that specifies the type of the service, with associating the service with a specified port. Specify only one of *pPortType* and *pPortName*.

### `pAny` [in, optional]

Optional reference to an extensible section to be included in the dynamic service metadata.

### `pService` [in, optional]

 Optional reference to a host service object to register.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pszServiceId* is **NULL**. |
| **E_INVALIDARG** | The length in characters of *pszServiceId* or *pszEndpointAddress* exceeds WSD_MAX_TEXT_LENGTH (8192), or both *pPortType* and *pPortName* are specified. |
| **E_FAIL** | The method failed. It may have failed because the host has not been initialized, or the service specified by *pszServiceId* could not be found. Call [Init](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-init) to initialize a device host. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

When this method is called, the device adds a reference to the service object and calls its methods in response to request messages addressed to the service. Call the [RemoveDynamicService](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-removedynamicservice) method on the device host to release its reference to the service and stop calling methods on the service.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)