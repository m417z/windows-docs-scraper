# IX509PrivateKey::Close

## Description

The **Close** method releases the handle of the cryptographic service provider (CSP) or the handle of the Cryptography API: Next Generation (CNG) key storage provider (KSP).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method does not delete the key from storage or the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) instance. For more information, see the [Delete](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-delete) method.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)