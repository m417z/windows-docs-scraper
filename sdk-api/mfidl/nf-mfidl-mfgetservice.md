# MFGetService function

## Description

Queries an object for a specified service interface.

This function is a helper function that wraps the [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) method. The function queries the object for the [IMFGetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfgetservice) interface and, if successful, calls **GetService** on the object.

## Parameters

### `punkObject`

A pointer to the **IUnknown** interface of the object to query.

### `guidService`

The service identifier (SID) of the service. For a list of service identifiers, see [Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces).

### `riid`

The interface identifier (IID) of the interface being requested.

### `ppvObject`

Receives the interface pointer. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_UNSUPPORTED_SERVICE** | The service requested cannot be found in the object represented by *punkObject*. |

## See also

[IMFGetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfgetservice)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces)