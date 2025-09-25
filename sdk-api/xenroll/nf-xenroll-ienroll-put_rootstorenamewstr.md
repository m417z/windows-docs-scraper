# IEnroll::put_RootStoreNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RootStoreNameWStr** property sets or retrieves the name of the root store where all intrinsically trusted, self-signed [root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) are kept.

 The default value for this property is "ROOT". Because of the level of trust associated with the root store, the user may be prompted (by means of the user interface) to accept the certificate. Although this property need not be changed for many applications, to avoid the user interface associated with trusting [root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), a possibility is to set **RootStoreNameWStr** to "CA".

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

**RootStoreNameWStr** affects the behavior of the following methods:

* [acceptPKCS7Blob](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptpkcs7blob)
* [acceptFilePKCS7WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-acceptfilepkcs7wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)