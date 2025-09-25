# ICertEncodeDateArray::GetCount

## Description

The **GetCount** method returns the number of **DATE** values in the object's **DATE** array.

## Parameters

### `pCount` [out]

A pointer to a **LONG** that receives the number of **DATE** values contained in the **DATE** array.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of **DATE** values contained in the **DATE** array.

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::GetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-getvalue)

[ICertEncodeDateArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-reset)