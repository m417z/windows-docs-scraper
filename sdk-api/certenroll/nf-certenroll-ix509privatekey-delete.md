# IX509PrivateKey::Delete

## Description

The **Delete** method releases the handle of the cryptographic service provider (CSP) or the handle of the Cryptography API: Next Generation (CNG) key storage provider (KSP) and deletes the key from disk or smart card.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The CSP could not be found. |

## Remarks

Call the [Close](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-close) method if you only want to close the provider handles. The **Delete** method does not delete the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) instance.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)