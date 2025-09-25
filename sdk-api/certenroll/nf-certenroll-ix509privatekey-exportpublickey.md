# IX509PrivateKey::ExportPublicKey

## Description

The **ExportPublicKey** method exports the public key portion of the asymmetric key pair.

## Parameters

### `ppPublicKey` [out]

Address of a variable that receives a pointer to an [IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey) interface that represents the key.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-open) or [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create) to open the private key before calling this method.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)