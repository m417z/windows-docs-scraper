# IEnroll4::acceptResponseBlob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptResponseBlob** method accepts delivery of the credentials issued in response to an earlier call to
[createRequestWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll4-createrequestwstr) and places the credentials in the appropriate store.

The response may be a [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) format or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pblobResponse` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the response.

## Remarks

The response must contain exactly one certificate; a child certificate cannot be present.

The response may be either a PKCS #7 or a full CMC response; however, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)