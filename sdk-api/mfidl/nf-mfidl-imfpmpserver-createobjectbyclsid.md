# IMFPMPServer::CreateObjectByCLSID

## Description

Creates an object in the protected media path (PMP) process.

## Parameters

### `clsid` [in]

CLSID of the object to create.

### `riid` [in]

Interface identifier of the interface to retrieve.

### `ppObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFPMPServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpserver)