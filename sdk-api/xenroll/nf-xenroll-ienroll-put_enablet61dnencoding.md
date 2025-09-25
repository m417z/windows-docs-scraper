# IEnroll::put_EnableT61DNEncoding

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **EnableT61DNEncoding** property sets or retrieves a Boolean value that determines whether the distinguished name in the request is encoded as a T61 string instead of as a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

 A T61 character is 8 bits, hence all [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters to be encoded must be less than or equal to 0xFF. This property was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

This property is read/write.

## Parameters

## Remarks

The **EnableT61DNEncoding** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)