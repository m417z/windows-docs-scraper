# IEnroll::getCertContextFromPKCS7

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getCertContextFromPKCS7** method retrieves a certificate context based on a PKCS #7 message that was issued in response to a PKCS #10 certificate request.

This method retrieves the context for the single certificate that was issued even though a PKCS #7 message may contain many certificates specifying the certification chain of authority that issued the certificate.

This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pBlobPKCS7` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the PKCS #7.

## Return value

The return value is a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) representing the certificate context, or **NULL** if the method fails.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll)

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)