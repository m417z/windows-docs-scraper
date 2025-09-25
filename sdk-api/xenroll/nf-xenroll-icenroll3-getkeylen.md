# ICEnroll3::GetKeyLen

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetKeyLen** method retrieves the minimum and maximum key lengths for the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). This method was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface. The values retrieved by this method are dependent upon the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `fMin` [in]

Boolean value indicating which key length (minimum or maximum) is retrieved. If *fMin* is **TRUE**, the minimum key length is retrieved; if it is **FALSE**, the maximum key length is retrieved.

### `fExchange` [in]

Boolean value indicating the type of key. If *fExchange* is **TRUE**, the exchange key length is retrieved; if it is **FALSE**, the signature key length is retrieved.

### `pdwKeySize` [out]

Pointer that receives the key's minimum or maximum length, in bits.

## Return value

### C++

If the method succeeds, the method returns S_OK, and **pdwKeySize* will be the value representing the length (in bits) for the key's minimum or maximum length.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A value that represents the length, in bits, for the key's minimum or maximum length.

## Remarks

Call this method to determine the minimum and maximum key lengths. If a CSP does not support this method, an error is returned.

#### Examples

```cpp
DWORD dwExchMin, dwExchMax, dwSignMin, dwSignMax;

// Determine the minimum and maximum key length values.
// hr is HRESULT variable.
hr = pEnroll->GetKeyLen( TRUE, TRUE, &dwExchMin );
if ( FAILED( hr ) )
    printf("Failed GetKeyLen for Exchange Minimum [%x]\n", hr);
else
    printf("Exchange key Min: %d\n", dwExchMin);

hr = pEnroll->GetKeyLen( FALSE, TRUE, &dwExchMax );
if ( FAILED( hr ) )
    printf("Failed GetKeyLen for Exchange Maximum [%x]\n", hr);
else
    printf("Exchange key Max: %d\n", dwExchMax );

hr = pEnroll->GetKeyLen( TRUE, FALSE, &dwSignMin );
if ( FAILED( hr ) )
    printf("Failed GetKeyLen for Signature Minimum [%x]\n", hr);
else
    printf("Signature key Min: %d\n", dwSignMin );

hr = pEnroll->GetKeyLen( FALSE, FALSE, &dwSignMax );
if ( FAILED( hr ) )
    printf("Failed GetKeyLen for Signature Maximum [%x]\n", hr);
else
    printf("Signature key Max: %d\n", dwSignMax );
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)