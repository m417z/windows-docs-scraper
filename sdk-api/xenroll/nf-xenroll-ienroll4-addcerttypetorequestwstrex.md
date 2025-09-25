# IEnroll4::AddCertTypeToRequestWStrEx

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **AddCertTypeToRequestWStrEx** method, like the
[AddCertTypeToRequestWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-addcerttypetorequestwstr) method, adds a certificate template (also known as certificate type) to a request.

This method is associated with the Certificate Services enterprise
[policy module](https://learn.microsoft.com/windows/desktop/SecCrypto/policy-modules). This method is specialized, and its use is not recommended for most applications. This version can add a V2 template extension into a request. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `lType` [in]

Indicates the version type of the template extension. It can be either of the following values.

| Value | Meaning |
| --- | --- |
| **XECT_EXTENSION_V1** | Uses a version 1 extension |
| **XECT_EXTENSION_V2** | Uses a version 2 extension |

### `pwszOIDOrName` [in]

A pointer to a null-terminated character string that represents the fully qualified name of the certificate template that is being added to the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This value is interpreted by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `lMajorVersion` [in]

Value that specifies the major version of the template. This parameter is ignored if *lType* is XECT_EXTENSION_V1.

### `fMinorVersion` [in]

Value that specifies whether a minor version of the template is used. This parameter is ignored if *lType* is XECT_EXTENSION_V1.

### `lMinorVersion` [in]

Value that specifies the minor version of the template. This parameter is ignored if *lType* is XECT_EXTENSION_V1 or if *fMinorVersion* is **FALSE**.

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## Remarks

This method supports only the new request method,
[createRequestWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll4-createrequestwstr). It does not support the
[createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr) method.

This method can be called multiple times to establish multiple certificate templates for the request.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)