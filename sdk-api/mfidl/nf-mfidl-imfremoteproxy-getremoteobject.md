# IMFRemoteProxy::GetRemoteObject

## Description

Retrieves a pointer to the remote object for which this object is a proxy.

## Parameters

### `riid` [in]

Interface identifier (IID) of the requested interface.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFRemoteProxy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfremoteproxy)