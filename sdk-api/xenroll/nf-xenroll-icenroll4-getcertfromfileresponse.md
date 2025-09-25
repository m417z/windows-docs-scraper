# ICEnroll4::getCertFromFileResponse

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getCertFromFileResponse** method retrieves the certificate from a file containing a response from a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).
This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `strResponseFileName` [in]

Specifies the name of the file that contains the response.

### `pstrCert` [out]

A pointer to a **BSTR** value that receives the certificate retrieved from the response. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **String** that contains a certificate.

## Remarks

The response contained in *strResponseFileName* must contain exactly one certificate; a child certificate cannot be present.

The response may be either a [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response. However, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

When this method is called from script, the method displays a user interface that asks whether the user will allow a read operation from the file system.