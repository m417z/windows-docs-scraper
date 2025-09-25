# ICertEncodeDateArray::GetValue

## Description

The **GetValue** method returns the specified date from the **DATE** array.

## Parameters

### `Index` [in]

The zero-based index that specifies the date to retrieve.

### `pValue` [out]

A pointer to a **DATE** variable that receives the date.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the **DATE** value at the specified index.

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::GetCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-getcount)

[ICertEncodeDateArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-setvalue)