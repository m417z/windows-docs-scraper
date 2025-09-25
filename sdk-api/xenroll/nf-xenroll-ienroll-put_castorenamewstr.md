# IEnroll::put_CAStoreNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CAStoreNameWStr** property sets or retrieves the name of the store where all non-"ROOT" and non-"MY" certificates are kept.

The default value for this property is "CA". This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **CAStoreNameWStr** property affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)