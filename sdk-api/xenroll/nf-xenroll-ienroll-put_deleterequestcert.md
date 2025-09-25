# IEnroll::put_DeleteRequestCert

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **DeleteRequestCert** property sets or retrieves a Boolean value that determines whether dummy certificates in the request store are deleted.

Dummy certificates are created for the purpose of persisting the keys generated for the PKCS #10 request during the enrollment process. The store specified by the
[RequestStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_requeststorenamewstr) property is where the dummy certificate is created. The newly generated keys are added as properties to the dummy certificate to persist them until a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) processes the request and responds with a PKCS #7. On acceptance of the PKCS #7, the dummy certificate is removed and the keys are added as properties of the issued certificate returned by the certification authority. For debugging and testing, it is often desirable to not delete the dummy certificate. Setting **DeleteRequestCert** to false prevents its deletion.

The default value for this property is true. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **DeleteRequestCert** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)