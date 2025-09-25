# IEnroll::get_ProviderType

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ProviderType** property sets or retrieves the type of provider.

The value of the **ProviderType** property is passed to the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI function. Valid values are determined by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in use. The default value for this property is 1. This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

For general information about provider types, see
[Cryptographic Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-types).

For more information about valid values for the Microsoft Base Cryptographic Provider, see the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI function.

For provider type information for other CSPs, see the documentation provided with the CSP.

The **ProviderType** property value is passed to [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) by using its *dwProvType* parameter.

The **ProviderType** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)
* [enumProvidersWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-enumproviderswstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)