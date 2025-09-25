# WSDCreateDeviceProxy2 function

## Description

Creates a device proxy that can support signed messages and returns a pointer to the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) interface.

## Parameters

### `pszDeviceId` [in]

The logical or physical address of the device. A logical address is of the form `urn:uuid:{guid}`. A physical address is a URI prefixed by http or https. If this address is a URI prefixed by https, then the proxy will use the SSL/TLS protocol.

The device address may be prefixed with the @ character. When *pszDeviceId* begins with @, this function does not retrieve the device metadata when creating the device proxy.

### `pszLocalId` [in]

The logical or physical address of the client, which is used to identify the proxy and to act as an event sink endpoint. A logical address is of the form `urn:uuid:{guid}`.

If the client uses a secure channel to receive events, then the address is a URI prefixed by https. This URI should specify port 5358, as this port is reserved for secure connections with WSDAPI. The port must be configured with an SSL server certificate before calling [WSDCreateDeviceProxyAdvanced](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-wsdcreatedeviceproxyadvanced). For more information about port configuration, see [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration).

### `pContext` [in]

An [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) object that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `pConfigParams` [in]

An array of [WSD_CONFIG_PARAM](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsd_config_param) structures that contain the parameters for creating the object.

### `dwConfigParamCount` [in]

The total number of structures passed in *pConfigParams*.

### `ppDeviceProxy` [out]

Pointer to an [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object that you use to represent a remote WSD device for client applications and middleware.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Function completed successfully. |
| **E_INVALIDARG** | *pszDeviceId* is **NULL**, *pszLocalId* is **NULL**, the length in characters of *pszDeviceId* exceeds WSD_MAX_TEXT_LENGTH (8192), or the length in characters of *pszLocalId* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_POINTER** | *ppDeviceProxy* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The **WSDCreateDeviceProxy2** function calls the [IWSDDeviceProxy::Init](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-init) method, which initializes an instance of an [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object.

This function will also retrieve the device metadata, unless the *pszDeviceId* parameter begins with the @ character. To retrieve device metadata after the device proxy has been created, call [IWSDDeviceProxy::BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) and [IWSDDeviceProxy::EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata) on the returned [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object.

For information about troubleshooting **WSDCreateDeviceProxy2** function calls, see [Troubleshooting WSDAPI Applications](https://learn.microsoft.com/windows/desktop/WsdApi/troubleshooting-wsdapi-applications).