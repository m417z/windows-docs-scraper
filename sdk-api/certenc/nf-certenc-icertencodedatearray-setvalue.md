# ICertEncodeDateArray::SetValue

## Description

The **SetValue** method sets a **DATE** value at the specified index of the **DATE** array.

 You must call
the [ICertEncodeDateArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-reset) method before calling **SetValue** for the first time.

## Parameters

### `Index` [in]

The zero-based index that specifies the index of the date element to set.

### `Value` [in]

Specifies the **DATE** value to set.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::GetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-getvalue)

[ICertEncodeDateArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-reset)