# IEnroll::get_WriteCertToUserDS

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WriteCertToUserDS** property sets or retrieves a Boolean value that determines whether the certificate is written to the user's Active Directory store.

 This property should not need to be modified by most applications. This property was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

This property is read/write.

## Parameters

## Remarks

**WriteCertToUserDS** affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)