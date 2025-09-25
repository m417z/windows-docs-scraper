# ICEnroll4::binaryToString

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **binaryToString** method converts a binary data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to a string.
This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

This method uses the
[CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa) function to do the conversion.

## Parameters

### `Flags` [in]

The value passed to the *dwFlags* parameter of the [CryptBinaryToString](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptbinarytostringa) function. For a description of possible values, see
**CryptBinaryToString**.

### `strBinary` [in]

A binary data BLOB to be converted to a string.

### `pstrEncoded` [out]

A pointer to a **BSTR** that receives the encoded data. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that represents the binary data.