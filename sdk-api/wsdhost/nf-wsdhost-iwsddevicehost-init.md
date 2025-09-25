# IWSDDeviceHost::Init

## Description

Initializes an instance of an [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) object, which is the host-side representation of a device.

## Parameters

### `pszLocalId` [in]

The logical or physical address of the device. A logical address is of the form `urn:uuid:{guid}`. If *pszLocalId* is a logical address, the host will announce the logical address and then convert the address to a physical address when it receives Resolve or Probe messages.

If *pszLocalId* is a physical address (such as URL prefixed by http or https), the host will use the address as the physical address and will host on that address instead of the default one.

For secure communication, *pszLocalId* must be an URL prefixed by https, and the host will use the SSL/TLS protocol on the port specified in the URL. The recommended port is port 5358, as this port is reserved for secure connections with WSDAPI.
If no port is specified, then the host will use port 443. The host port must be configured with an SSL server certificate. For more information about the configuration of host ports, see [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration).

Any URL (http or https) must be terminated with a trailing slash. The URL must contain a valid IP address or hostname.

The following list shows some example values for *pszLocalId*. It is not a complete list of valid values.

* http://192.168.0.1:5357/
* http://localhost/
* http://myHostname:5357/
* https://192.168.0.1:5358/
* https://myHostname/
* https://myHostname/myDevice/
* https://myHostname:5358/

### `pContext` [in, optional]

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) interface that defines custom message types or namespaces.

### `ppHostAddresses` [in, optional]

A single [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) object or [IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress) object. The objects provide information about specific addresses that the host should listen on.

If *pszLocalId* contains a local address, the resulting behavior is a mapping between the logical address and the supplied physical address (instead of a mapping between the logical address and the default physical address).

### `dwHostAddressCount` [in, optional]

The number of items in the *ppHostAddresses* array. If *ppHostAddresses* is an [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interface, count must be 1.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszLocalId* is **NULL**, the length in characters of *pszLocalId* exceeds WSD_MAX_TEXT_LENGTH (8192), or the number of addresses referenced by *ppHostAddresses* does not match *dwHostAddressCount*. |
| **E_FAIL** | The device host is in an unexpected state. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ABORT** | Initialization could not be completed. |

## Remarks

This method is called by [WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost) and need not normally be called directly by your code.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)