# ICertEncodeBitString::GetBitString

## Description

The **GetBitString** method returns the string of bits in the object's bit string.

## Parameters

### `pstrBitString` [out]

A pointer to a **BSTR** that will contain the bit string. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the bit string.

## See also

[ICertEncodeBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodebitstring)