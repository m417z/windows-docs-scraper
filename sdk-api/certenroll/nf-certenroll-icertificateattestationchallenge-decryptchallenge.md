# ICertificateAttestationChallenge::DecryptChallenge

## Description

Decrypts the challenge from the [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response and creates a re-encrypted response to send to the CA.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the attestation challenge. The default value is XCN_CRYPT_STRING_BASE64.

### `pstrEnvelopedPkcs7ReencryptedToCA` [out, retval]

The decrypted challenge from the CMC response re-encrypted for the CA.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICertificateAttestationChallenge](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificateattestationchallenge)