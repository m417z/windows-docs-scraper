# IEnroll::get_MyStoreTypeWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **MyStoreTypeWStr** property sets or retrieves the type of store specified by the
**MyStoreTypeWStr** property. This store type is passed directly on to [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore).

The default value for this property is sz_CERT_STORE_PROV_SYSTEM. Only system stores are supported. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **MyStoreTypeWStr** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)