# ICertEncodeStringArray::SetValue

## Description

The **SetValue** method sets a string value at the specified index of the string array.

 You must call the
[ICertEncodeStringArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-reset) method before calling **SetValue** for the first time.

## Parameters

### `Index` [in]

The zero-based index that specifies the element of the string array to set.

### `str` [in]

Specifies the string value to set.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)

[ICertEncodeStringArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-reset)