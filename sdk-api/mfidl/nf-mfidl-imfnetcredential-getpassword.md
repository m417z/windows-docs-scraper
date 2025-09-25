# IMFNetCredential::GetPassword

## Description

Retrieves the password.

## Parameters

### `pbData` [out]

Pointer to a buffer that receives the password. To find the required buffer size, set this parameter to **NULL**. If *fEncryptData* is **FALSE**, the buffer contains a wide-character string. Otherwise, the buffer contains encrypted data.

### `pcbData` [in, out]

On input, specifies the size of the *pbData* buffer, in bytes. On output, receives the required buffer size. If *fEncryptData* is **FALSE**, the size includes the terminating null character.

### `fEncryptData` [in]

If **TRUE**, the method returns an encrypted string. Otherwise, the method returns an unencrypted string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the password is not available, the method might succeed and set **pcbData* to zero.

## See also

[IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential)