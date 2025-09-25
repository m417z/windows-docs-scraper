# MFCreateCredentialCache function

## Description

Creates a credential cache object. An application can use this object to implement a custom credential manager.

## Parameters

### `ppCache`

Receives a pointer to the [IMFNetCredentialCache](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialcache) interface of the new credential cache object. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[IMFNetCredentialCache](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialcache)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)