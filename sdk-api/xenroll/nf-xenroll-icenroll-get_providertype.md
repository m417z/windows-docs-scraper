# ICEnroll::get_ProviderType

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ProviderType** property sets or retrieves the type of provider.

The value of the **ProviderType** property is passed to the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI function. Valid values are determined by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in use. The default value for this property is 1. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

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

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)
* [enumProviders](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-enumproviders)

#### Examples

```cpp
DWORD    dwProvType;
HRESULT  hr;

// Get the ProviderType value.
// pEnroll is previously instantiated ICEnroll interface pointer
hr = pEnroll->get_ProviderType(&dwProvType);
if (FAILED( hr ))
    printf("Failed get_ProviderType - %x\n", hr);
else
    printf("ProviderType: %d\n", dwProvType);

// Set the ProviderType value.
hr = pEnroll->put_ProviderType(PROV_MS_EXCHANGE);
if (FAILED(hr))
    printf("Failed put_ProviderType - %x\n", hr);
else
    printf("ProviderType set to %d\n", PROV_MS_EXCHANGE);
```