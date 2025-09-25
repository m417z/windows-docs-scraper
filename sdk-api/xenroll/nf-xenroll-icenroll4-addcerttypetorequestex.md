# ICEnroll4::addCertTypeToRequestEx

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addCertTypeToRequestEx** method, like the
[addCertTypeToRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll2-addcerttypetorequest) method, adds a certificate template (or "certificate type") to a request. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

This method is associated with the Certificate Services enterprise
[policy module](https://learn.microsoft.com/windows/desktop/SecCrypto/policy-modules). This method is specialized, and its use is not recommended for most applications. This version can add a V@ template extension into a request.

## Parameters

### `lType` [in]

Indicates the version type of the template extension. This can be either of the following values:

| Value | Meaning |
| --- | --- |
| **XECT_EXTENSION_V1** | Uses a version 1 extension |
| **XECT_EXTENSION_V2** | Uses a version 2 extension |

### `bstrOIDOrName` [in]

The certificate template fully qualified name which is being added to the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This value is interpreted by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `lMajorVersion` [in]

Sets the major version of the template. This parameter is ignored if *lFlag* is XECT_EXTENSION_V!.

### `fMinorVersion` [in]

Indicates whether a minor version of the template is used. This parameter is ignored if *lFlag* is XECT_EXTENSION_V!.

### `lMinorVersion` [in]

Sets the minor version of the template. This parameter is ignored if *lFlag* is XECT_EXTENSION_V1 or if *fMinorVersion* is **FALSE**.

## Return value

### VB

The return value is an **HRESULT**, with **S_OK** returned if the call is successful.

## Remarks

This method supports only the new request method,
[createRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-createrequest). It does not support the
[createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10) method.

This method can be called multiple times to establish multiple certificate templates for the request.

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll2::addCertTypeToRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll2-addcerttypetorequest)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[ICEnroll4::createRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-createrequest)

[ICEnroll::createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)