# ICEnroll::put_ProviderFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ProviderFlags** property sets or retrieves the provider type.

The **ProviderFlags** property is passed to the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI function. Valid values are determined by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in use.

The default value for this property is zero. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

For more information about valid **ProviderFlags** values for the Microsoft Base Cryptographic Provider, see the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI function.

For information about other CSPs, see the documentation provided with the CSP.

The **ProviderFlags** property value is passed to [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) by using its *dwFlags* parameter.

The **ProviderFlags** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
DWORD    dwProvFlags;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer
// get the ProviderFlags value
hr = pEnroll->get_ProviderFlags( &dwProvFlags );
if (FAILED( hr ))
    printf("Failed get_ProviderFlags - %x\n", hr );
else
    printf( "ProviderFlags: %d\n", dwProvFlags );

// Set the ProviderFlags value.
hr = pEnroll->put_ProviderFlags(CRYPT_MACHINE_KEYSET);
if (FAILED( hr ))
    printf("Failed put_ProviderFlags - %x\n", hr );
else
    printf( "ProviderFlags set to %d\n", CRYPT_MACHINE_KEYSET  );
```