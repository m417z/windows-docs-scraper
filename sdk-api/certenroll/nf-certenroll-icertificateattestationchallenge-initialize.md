# ICertificateAttestationChallenge::Initialize

## Description

Initialize using the full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response returned from the CA.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the response. The default value is XCN_CRYPT_STRING_BASE64.

### `strPendingFullCmcResponseWithChallenge` [in]

The pending CMC response from the CA.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The CA should have returned a pending CMC response. The content of the CMC response should contain a challenge. There must be only one CMC response and it must contain pending information.

## See also

[ICertificateAttestationChallenge](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificateattestationchallenge)