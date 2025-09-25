# ICertEncodeLongArray::SetValue

## Description

The **SetValue** method sets a **Long** value at the specified index of the **Long** array.

 You must call
[ICertEncodeLongArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-reset) before calling **SetValue** for the first time.

## Parameters

### `Index` [in]

The zero-based index that specifies the index of the array element to set.

### `Value` [in]

Specifies the **Long** value to set.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeLongArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodelongarray)

[ICertEncodeLongArray::GetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-getvalue)

[ICertEncodeLongArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-reset)