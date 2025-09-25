# IEnroll4::binaryBlobToString

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **binaryBlobToString** method converts a binary data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to a string. This method uses the
[CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa) function to perform the conversion. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `Flags` [in]

Value passed to the *dwFlags* parameter of the [CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa) function. For a description of possible values, see
[CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa).

### `pblobBinary` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that represents the binary BLOB to convert to a string.

### `ppwszString` [out]

A pointer to a **LPWSTR** that receives the encoded data.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)