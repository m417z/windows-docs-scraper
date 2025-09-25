# IX509EndorsementKey::AddCertificate

## Description

Add an endorsement key certificate to the key storage provider (KSP) that supports endorsement keys. You can only call the **AddCertificate** method after the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509endorsementkey-open) method has been successfully called.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the certificate. The default value is XCN_CRYPT_STRING_BASE64.

### `strCertificate` [in]

The certificate to add to the store. The public key from this certificate must match the public key of the endorsement key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only non-manufacturer certificates can be added to the key storage provider.

## See also

[IX509EndorsementKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509endorsementkey)