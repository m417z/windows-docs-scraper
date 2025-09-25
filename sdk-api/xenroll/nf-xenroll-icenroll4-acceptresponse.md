# ICEnroll4::acceptResponse

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptResponse** method accepts delivery of the credentials issued in response to an earlier call to
[createRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-createrequest) and places the credentials in the appropriate store. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

The response may be a [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) format or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response.

## Parameters

### `strResponse` [in]

A string that represents the base64-encoded response.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The response must contain exactly one certificate; a child certificate cannot be present.

The response may be either a PKCS #7 or a full CMC response; however, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

When this method is called from script, the method displays a user interface that asks whether the user will allow installation of a certificate.