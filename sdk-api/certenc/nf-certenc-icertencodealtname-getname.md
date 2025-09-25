# ICertEncodeAltName::GetName

## Description

The **GetName** method returns the specified name from the alternate name array.

## Parameters

### `NameIndex` [in]

A zero-based index that specifies the index of the alternate name entry to retrieve.

To retrieve the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of a CERT_ALT_NAME_OTHER_NAME name, combine the index value with EAN_NAMEOBJECTID (defined as 0x80000000) with a bitwise-**OR** operation. Otherwise, the binary value is retrieved. To determine the type of name, call the [ICertEncodeAltName::GetNameChoice](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-getnamechoice) method.

### `pstrName` [out]

A pointer to a **BSTR** that receives the alternate name. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the alternate name at the specified index. The return value is a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

## See also

[ICertEncodeAltName](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodealtname)

[ICertEncodeAltName::GetNameChoice](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-getnamechoice)

[ICertEncodeAltName::SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-setnameentry)