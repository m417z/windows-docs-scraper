# IMFGetService::GetService

## Description

Retrieves a service interface.

## Parameters

### `guidService` [in]

The service identifier (SID) of the service. For a list of service identifiers, see [Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces).

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives the interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_UNSUPPORTED_SERVICE** | The object does not support the service. |

## See also

[IMFGetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfgetservice)

[MFGetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfgetservice)

[Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces)