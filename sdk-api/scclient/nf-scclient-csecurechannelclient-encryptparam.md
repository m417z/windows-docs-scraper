# CSecureChannelClient::EncryptParam

## Description

The **EncryptParam** method encrypts data being sent out through a parameter. Data is encrypted in-place, in the submitted buffer.

## Parameters

### `pbData` [in, out]

Pointer to the data buffer that holds the information to encrypt. Encryption is handled in-place in the buffer, and the retrieved encrypted data is the same size as the original data.

### `dwDataLen` [in]

Pointer to a **DWORD** specifying the length of the *pbData* buffer.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| S_OK | The method succeeded. |
| E_INVALIDARG | A parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

This method is used to encrypt data before sending it to the device in [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata).

Encrypt only the parameters that are specified as requiring encryption. See [Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels) for a table of methods that must use the message authentication code algorithm and encrypted parameters.

For example code, see [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata).

## See also

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)

[CSecureChannelClient::DecryptParam](https://learn.microsoft.com/previous-versions/bb231586(v=vs.85))

[IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)