# ICertEncodeDateArray::Reset

## Description

The **Reset** method specifies the size of **DATE** array in this object. The values of all the elements in the array are set to zero. You must call this method before calling the [ICertEncodeDateArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-setvalue) method for the first time.

## Parameters

### `Count` [in]

Specifies the number of elements in the **DATE** array.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-setvalue)