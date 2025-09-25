# IEnroll::get_CAStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CAStoreFlags** property sets or retrieves a flag that controls the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) store when the store is opened. This flag is passed to the *dwFlags* parameter of the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function when the CA store is opened.

The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **CAStoreFlags** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)