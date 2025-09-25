# IEnroll4::acceptFileResponseWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptFileResponseWStr** method accepts delivery of the credentials issued in response to an earlier call to
[createFileRequestWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll4-createfilerequestwstr), and it places the credentials in the appropriate store.

The response may be a [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) message or a [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pwszResponseFileName` [in]

A pointer to a null-terminated wide character string that represents the name of the file that contains the response.

## Remarks

The response named in the *pwszResponseFileName* parameter must contain exactly one certificate; a child certificate cannot be present.

The response may be either a PKCS #7 or a full CMC response; however, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)