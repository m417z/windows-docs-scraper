# WSDCreateDeviceHost2 function

## Description

Creates a device host that can support signed messages and returns a pointer to the [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) interface.

## Parameters

### `pszLocalId` [in]

The logical or physical address of the device. A logical address is of the form `urn:uuid:{guid}`. If *pszLocalId* is a logical address, the host will announce the logical address and then convert the address to a physical address when it receives Resolve or Probe messages.

If *pszLocalId* is a physical address (such as URL prefixed by http or https), the host will use the address as the physical address and will host on that address instead of the default one.

If *pszLocalId* is an HTTPS URL, the recommended port is port 5358, as this port is reserved for secure connections with WSDAPI.
If no port is specified, then the host will use port 443. The host port must be configured with an SSL server certificate before calling [WSDCreateDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-wsdcreatedevicehost). For more information about the configuration of host ports, see [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration).

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

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) object that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `pConfigParams` [in]

An array of [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) structures that contain the parameters for creating the object.

### `dwConfigParamCount` [in]

The total number of structures passed in *pConfigParams*.

### `ppDeviceHost` [out]

Pointer to an [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) object that you use to expose the WSD-specific device semantics associated with a server that responds to incoming requests.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Function completed successfully. |
| **E_INVALIDARG** | *pszLocalId* is **NULL** or the length in characters of *pszLocalId* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_POINTER** | *ppDeviceHost* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The **WSDCreateDeviceHost2** function calls the [IWSDDeviceHost::Init](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-init) method, which initializes an instance of an [IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost) object.