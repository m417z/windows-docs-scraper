# ICertEncodeLongArray::GetValue

## Description

The **GetValue** method returns the specified **Long** value from the **Long** array.

## Parameters

### `Index` [in]

The zero-based index that specifies the **Long** value to retrieve.

### `pValue` [out]

A pointer to a **Long** variable that receives the value.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the **Long** value at the specified index.

## See also

[ICertEncodeLongArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodelongarray)

[ICertEncodeLongArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-setvalue)