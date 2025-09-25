# ICEnroll4::GetKeyLenEx

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetKeyLenEx** method retrieves size information for the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

The values retrieved by this method are dependent upon the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Parameters

### `lSizeSpec` [in]

A value that indicates the type of size information to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XEKL_KEYSIZE_MIN** | The minimum key size. |
| **XEKL_KEYSIZE_MAX** | The maximum key size. |
| **XEKL_KEYSIZE_INC** | The size of the key increment. For more information, see Remarks. |

### `lKeySpec` [in]

Specifies the key for which size information is returned. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XEKL_KEYSPEC_KEYX** | Exchange key |
| **XEKL_KEYSPEC_SIG** | Signature key |

### `pdwKeySize` [out]

A pointer to a variable that receives the key size, in bits.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

A value that represents the key size, in bits.

## Remarks

If the CSP does not support this method, an error is returned.

For more information about the XEKL_KEYSIZE_INC value, see PP_SIG_KEYSIZE_INC usage in the
[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) reference page.

#### Examples

```cpp
DWORD dwExchMin, dwExchMax, dwSignDef, dwSignInc;

// Determine the minimum and maximum key length values.
// hr is HRESULT variable.
hr = pEnroll4->GetKeyLenEx( XEKL_KEYSIZE_MIN,
                            XEKL_KEYSPEC_KEYX,
                            &dwExchMin );
if ( FAILED( hr ) )
    printf("Failed GetKeyLenEx for Exchange Minimum [%x]\n", hr);
else
    printf("Exchange key Min: %d\n", dwExchMin);

hr = pEnroll4->GetKeyLenEx( XEKL_KEYSIZE_MAX,
                            XEKL_KEYSPEC_KEYX,
                            &dwExchMax );
if ( FAILED( hr ) )
    printf("Failed GetKeyLenEx for Exchange Maximum [%x]\n", hr);
else
    printf("Exchange key Max: %d\n", dwExchMax );

hr = pEnroll4->GetKeyLenEx( XEKL_KEYSIZE_DEFAULT,
                            XEKL_KEYSPEC_SIG,
                            &dwSignDef );
if ( FAILED( hr ) )
    printf("Failed GetKeyLenEx for Signature Default "
   "Key size [%x]\n", hr);
else
    printf("Signature key default size: %d\n", dwSignDef );

hr = pEnroll4->GetKeyLenEx( XEKL_KEYSIZE_INC,
                            XEKL_KEYSPEC_SIG,
                            &dwSignInc );
if ( FAILED( hr ) )
    printf("Failed GetKeyLenEx for Signature "
   "Key Size Increment [%x]\n", hr);
else
    printf("Signature key increment size: %d\n", dwSignInc );
```