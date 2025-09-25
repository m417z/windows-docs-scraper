# IEnroll::get_MyStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **MyStoreFlags** property sets or retrieves the registry location used for the MY store.

The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **MyStoreFlags** property value is passed to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) CryptoAPI function by using its *dwFlags* parameter.

The **MyStoreFlags** property should be set before using the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)