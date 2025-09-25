# IX509EndorsementKey::RemoveCertificate

## Description

Removes an endorsement certificate related to the endorsement key from the key storage provider. You can only call the **RemoveCertificate** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the endorsement certificate. The default value is XCN_CRYPT_STRING_BASE64.

### `strCertificate` [in]

The certificate to remove from the store.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only non-manufacturer certificates can be removed from the key storage provider.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)