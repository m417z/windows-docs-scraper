# IWSDDeviceProxy::Init

## Description

Initializes the device proxy, optionally sharing a session with a previously initialized sponsoring device proxy.

## Parameters

### `pszDeviceId` [in]

The logical address (ID) of the device.

### `pDeviceAddress` [in]

Reference to an [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) object that contains the device configuration data.

### `pszLocalId` [in]

The logical address of the client. The logical address is of the form, urn:uuid:{guid}. Used when the server needs to initiate a connection to the client.

### `pContext` [in, optional]

Reference to an [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) object that defines custom message types or namespaces.

If **NULL**, a default context representing the built-in message types and namespaces is used.

### `pSponsor` [in, optional]

Reference to an [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object that is an optional device with which to share a session and lower layers.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszDeviceId* is **NULL**, *pszLocalId* is **NULL**, or the length in characters of either identifier string exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method is called by [WSDCreateDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-wsdcreatedeviceproxy) and need not normally be called directly by the client code.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)