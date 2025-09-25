# CSecureChannelClient::DecryptParam

## Description

The **DecryptParam** method decrypts data received through a parameter. Encryption is performed in-place on the encrypted data.

## Parameters

### `pbData` [in, out]

Pointer to the data buffer that holds the information to decrypt. On input contains the encrypted data; on output, contains the decrypted data. The decrypted data is the same length as the encrypted data.

### `dwDataLen` [in]

Pointer to a **DWORD** specifying the length of the buffer to which *pbData* points.

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

This is used by [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata) to decrypt data read from the device.

For robustness, before calling the **DecryptParam** method, components should copy the data to a temporary buffer and then use **DecryptParam** to decrypt the temporary buffer. Decryption is handled in-place in the buffer; the buffer does not need to be resized.

For example code, see [IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata).

## See also

[CSecureChannelClient Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelclient-class)

[CSecureChannelClient::EncryptParam](https://learn.microsoft.com/previous-versions/bb231587(v=vs.85))

[IWMDMOperation::TransferObjectData](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-transferobjectdata)

[Using Secure Authenticated Channels](https://learn.microsoft.com/windows/desktop/WMDM/using-secure-authenticated-channels)