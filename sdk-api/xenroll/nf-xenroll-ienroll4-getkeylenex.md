# IEnroll4::GetKeyLenEx

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetKeyLenEx** method retrieves size information for the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

The values retrieved by this method are dependent upon the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `lSizeSpec` [in]

Value indicating the type of size information to be retrieved. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **XEKL_KEYSIZE_MIN** | Minimum key size. |
| **XEKL_KEYSIZE_MAX** | Maximum key size. |
| **XEKL_KEYSIZE_INC** | Size of key increment. For more information, see Remarks. |

### `lKeySpec` [in]

Specifies the key for which size information is returned. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **XEKL_KEYSPEC_KEYX** | Exchange key |
| **XEKL_KEYSPEC_SIG** | Signature key |

### `pdwKeySize` [out]

A pointer to **LONG** that receives the key size information, in bits.

## Remarks

If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) does not support this method, an error is returned.

For additional details on the XEKL_KEYSIZE_INC value, see PP_SIG_KEYSIZE_INC usage in the
[CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) reference page.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)