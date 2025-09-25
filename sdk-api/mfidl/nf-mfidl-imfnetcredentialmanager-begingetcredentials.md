# IMFNetCredentialManager::BeginGetCredentials

## Description

Begins an asynchronous request to retrieve the user's credentials.

## Parameters

### `pParam` [in]

Pointer to an [MFNetCredentialManagerGetParam](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfnetcredentialmanagergetparam) structure.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetCredentialManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialmanager)