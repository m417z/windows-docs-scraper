# ICertEncodeStringArray::GetValue

## Description

The **GetValue** method returns the specified string from the string array.

## Parameters

### `Index` [in]

The zero-based index that specifies the string to retrieve.

### `pstr` [out]

A pointer to a **BSTR** that represents the string value. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the string value at the specified index.

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)

[ICertEncodeStringArray::GetStringType](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-getstringtype)

[ICertEncodeStringArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-setvalue)