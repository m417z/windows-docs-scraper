# IEnroll::put_RequestStoreNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RequestStoreNameWStr** property sets or retrieves the name of the store that contains the dummy certificate. This dummy certificate, along with the added private keys, remains in the request store until a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) processes the request and responds with a PKCS #7.

The default value for this property is "REQUEST". If the default is not to be used, this property must be set to the store to be used before calls to
[createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)**/**[createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr) and again before calls to
[acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)**/**[acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr).

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

Typically, modification of the **RequestStoreNameWStr** property is performed only in advanced applications. Changing this value is not recommended for most applications.

The **RequestStoreNameWStr** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)
* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll)

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)