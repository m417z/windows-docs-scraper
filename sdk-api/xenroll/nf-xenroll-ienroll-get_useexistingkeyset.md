# IEnroll::get_UseExistingKeySet

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **UseExistingKeySet** property sets or retrieves a Boolean value that determines whether the existing keys should be used.

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

 If an existing key set is used, the **UseExistingKeySet** property must be set to true.

The **UseExistingKeySet** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)