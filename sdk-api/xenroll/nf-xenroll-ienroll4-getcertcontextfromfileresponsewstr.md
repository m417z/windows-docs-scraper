# IEnroll4::getCertContextFromFileResponseWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getCertContextFromFileResponseWStr** method retrieves the certificate from a file containing a response from a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pwszResponseFileName` [in]

A pointer to a null-terminated wide character string that represents the name of the file containing the response.

### `ppCertContext` [out]

A pointer to a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that receives the certificate retrieved from the response.

## Remarks

The response contained in *pwszResponseFileName* must contain exactly one certificate; a child certificate cannot be present.

The response may be either a PKCS #7 or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response. However, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)