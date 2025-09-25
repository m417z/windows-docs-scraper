# IMFNetCredential::SetPassword

## Description

Sets the password.

## Parameters

### `pbData` [in]

Pointer to a buffer that contains the password. If *fDataIsEncrypted* is **FALSE**, the buffer is a wide-character string. Otherwise, the buffer contains encrypted data.

### `cbData` [in]

Size of *pbData*, in bytes. If *fDataIsEncrypted* is **FALSE**, the size includes the terminating null character.

### `fDataIsEncrypted` [in]

If **TRUE**, the password is encrypted. Otherwise, the password is not encrypted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential)