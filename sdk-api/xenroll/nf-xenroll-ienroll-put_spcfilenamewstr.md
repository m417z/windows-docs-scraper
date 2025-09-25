# IEnroll::put_SPCFileNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **SPCFileNameWStr** property sets or retrieves the name of the file to which to write the base64-encoded PKCS #7 (in **BSTR** form) as returned from the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The file is written as a binary PKCS #7. Specifying this file does not affect the acceptance of the certificates into any of the user's stores.

If the file already exists, the user is notified and prompted for permission to overwrite it.

**SPCFileNameWStr** affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)