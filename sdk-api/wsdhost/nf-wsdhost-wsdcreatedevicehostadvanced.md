# WSDCreateDeviceHostAdvanced function

## Description

Creates a device host and returns a pointer to the [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) interface.

## Parameters

### `pszLocalId` [in]

The logical or physical address of the device. A logical address is of the form `urn:uuid:{guid}`. If *pszLocalId* is a logical address, the host will announce the logical address and then convert the address to a physical address when it receives Resolve or Probe messages.

If *pszLocalId* is a physical address (such as URL prefixed by http or https), the host will use the address as the physical address and will host on that address instead of the default one.

For secure communication, *pszLocalId* must be an URL prefixed by https, and the host will use the SSL/TLS protocol on the port specified in the URL. The recommended port is port 5358, as this port is reserved for secure connections with WSDAPI.
If no port is specified, then the host will use port 443. The host port must be configured with an SSL server certificate before calling **WSDCreateDeviceHostAdvanced**. For more information about the configuration of host ports, see [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration).

If either *pszLocalId* or the transport address referenced by *ppHostAddresses* is an URL prefixed by https, then both URLs must be identical. If this is not the case, **WSDCreateDeviceHostAdvanced** will return E_INVALIDARG.

Any URL (http or https) must be terminated with a trailing slash. The URL must contain a valid IP address or hostname.

The following list shows some example values for *pszLocalId*. It is not a complete list of valid values.

* http://192.168.0.1:5357/
* http://localhost/
* http://myHostname:5357/
* https://192.168.0.1:5358/
* https://myHostname/
* https://myHostname/myDevice/
* https://myHostname:5358/

### `pContext` [in]

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) interface that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `ppHostAddresses` [in]

A single [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interface or [IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress) interface. The objects provide information about specific addresses that the host should listen on.

If *pszLocalId* contains a logical address, the resulting behavior is a mapping between the logical address and a specific set of physical addresses (instead of a mapping between the logical address and a default physical address).

### `dwHostAddressCount` [in]

The number of items in the *ppHostAddresses* array. If *ppHostAddresses* is an [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interface, count must be 1.

### `ppDeviceHost` [out]

Pointer to the [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) interface that you use to expose the WSD-specific device semantics associated with a server that responds to incoming requests.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszLocalId* is **NULL**, the length in characters of *pszLocalId* exceeds WSD_MAX_TEXT_LENGTH (8192), or *pszLocalId* points to an URL prefixed by https and that URL does not match the URL of the transport address referenced by *ppHostAddresses*. |
| **E_POINTER** | *ppDeviceHost* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The **WSDCreateDeviceHostAdvanced** function calls the [IWSDDeviceHost::Init](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-init) method, which initializes an instance of an [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) object.

## See also

[WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost)