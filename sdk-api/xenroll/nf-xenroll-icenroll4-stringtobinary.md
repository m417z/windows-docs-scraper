# ICEnroll4::stringToBinary

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **stringToBinary** method converts an encoded string to a binary data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

The **stringToBinary** method calls the
[CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya) function.

## Parameters

### `Flags` [in]

A value passed to the *dwFlags* parameter of the [CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya) function. For valid values, see
[CryptStringToBinary](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptstringtobinarya).

### `strEncoded` [in]

An encoded string to be converted to a binary data [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

### `pstrBinary` [out]

A pointer to a **BSTR** that receives the binary data. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that contains the binary data.