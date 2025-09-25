# ICertEncodeCRLDistInfo::GetName

## Description

The **GetName** method returns the name at a specified index of a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution information point.

## Parameters

### `DistPointIndex` [in]

Specifies the index of the distribution point for which to get a name. The first value is at index zero.

### `NameIndex` [in]

Specifies the index of the name entry to get. The first value is at index zero.

### `pstrName` [out]

A pointer to a **BSTR** that represents the name value. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the name at the specified index of the specified distribution point. The return value is a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::GetNameCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getnamecount)

[ICertEncodeCRLDistInfo::SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-setnameentry)