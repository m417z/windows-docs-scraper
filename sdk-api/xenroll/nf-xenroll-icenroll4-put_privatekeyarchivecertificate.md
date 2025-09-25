# ICEnroll4::put_PrivateKeyArchiveCertificate

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **PrivateKeyArchiveCertificate** property sets or retrieves the certificate that is used to archive a private key with a PKCS #7 or [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) request.

If this property is not null, the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is encrypted based on the specified certificate and added to the request as an unauthenticated [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). This property was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

This property is read/write.

## Parameters