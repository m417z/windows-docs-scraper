# IMFNetCredentialManager::EndGetCredentials

## Description

Completes an asynchronous request to retrieve the user's credentials.

## Parameters

### `pResult` [in]

Pointer to an [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface that contains the asynchronous result.

### `ppCred` [out]

Receives a pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface, which is used to retrieve the credentials. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetCredentialManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialmanager)