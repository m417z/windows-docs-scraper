# IEnroll::get_MyStoreNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **MyStoreNameWStr** property sets or retrieves the name of the store where certificates with linked [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) are kept.

The value of **MyStoreNameWStr** specifies the store in which to place the new certificate produced from
[acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob) or
[acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr). The default value for this property is "MY". This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **MyStoreNameWStr** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)