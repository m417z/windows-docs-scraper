# IEnroll::put_ProviderNameWStr

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ProviderNameWStr** property sets or retrieves the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use.

If the CSP has not been specified, the default value for this property is "Microsoft Base Cryptographic Provider", and the **ProviderNameWStr** property is set to an empty string. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

The **ProviderNameWStr** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)
* [enumContainersWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-enumcontainerswstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)