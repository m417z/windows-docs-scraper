# ICEnroll3::GetSupportedKeySpec

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetSupportedKeySpec** method retrieves information regarding the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) support for signature and/or exchange operations. This method was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

The values retrieved by this method are dependent upon the current CSP.

## Parameters

### `pdwKeySpec` [out]

A pointer to a **LONG** that receives a bit flag that indicates whether the current CSP supports [exchange](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) and [signature keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a value that indicates whether the current CSP supports exchange and signature keys. If the CSP does not support this method, an error is returned.

## Remarks

Call this method to determine whether the current CSP supports exchange keys, signature keys, or both. The *pdwKeySpec* parameter will contain one or more of the following constants (defined in Wincrypt.h):

* AT_KEYEXCHANGE
* AT_SIGNATURE

#### Examples

```cpp
DWORD dwKeySpec;

// Determine the supported key specifications.
// hr is HRESULT variable.
hr = pEnroll->GetSupportedKeySpec( &dwKeySpec );
if ( FAILED( hr ) )
    printf("Failed GetSupportedKeySpec [%x]\n", hr);
else
{
    printf("Exchange keys are %s. Signature keys are %s.\n",
           dwKeySpec & AT_KEYEXCHANGE ? "supported" : "not supported",
           dwKeySpec & AT_SIGNATURE ? "supported" : "not supported" );
}
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)