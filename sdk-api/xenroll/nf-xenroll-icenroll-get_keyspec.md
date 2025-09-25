# ICEnroll::get_KeySpec

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **KeySpec** property sets or retrieves the type of key generated.

 Valid values are determined by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in use. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

For the Microsoft Base Cryptographic Provider, the **KeySpec** property has a value of AT_KEYEXCHANGE for [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly), or AT_SIGNATURE for signature keys. The default is AT_SIGNATURE.

For information about the other Microsoft CSPs, see
[Cryptographic Service Providers](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-service-providers) in the CryptoAPI 2.0 documentation.

For information about other CSPs, see the documentation provided with the CSP.

The **KeySpec** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
DWORD    dwKeySpec;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the KeySpec value
hr = pEnroll->get_KeySpec( &dwKeySpec );
if (FAILED( hr ))
    printf("Failed get_KeySpec - %x\n", hr );
else
    printf( "KeySpec: %d\n", dwKeySpec );

// set the KeySpec value
hr = pEnroll->put_KeySpec( AT_KEYEXCHANGE );
if (FAILED( hr ))
    printf("Failed put_KeySpec - %x\n", hr );
else
    printf( "KeySpec set to %d\n", AT_KEYEXCHANGE );
```