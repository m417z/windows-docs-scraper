# IEnroll::get_RequestStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RequestStoreFlags** property sets or retrieves the registry location used for the request store.

 The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **RequestStoreFlags** property value is passed to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) CryptoAPI function by using its *dwFlags* parameter.

Typically, modification of the **RequestStoreFlags** property is performed only in advanced applications.

The **RequestStoreFlags** property should be set before using the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)
* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)