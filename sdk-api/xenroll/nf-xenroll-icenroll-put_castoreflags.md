# ICEnroll::put_CAStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CAStoreFlags** property sets or retrieves a flag that controls the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) store when the store is opened. This flag is passed to the *dwFlags* parameter of the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function when the CA store is opened.

The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **CAStoreFlags** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
DWORD    dwFlags;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// retrieve the flag value
hr = pEnroll->get_CAStoreFlags( &dwFlags );
if ( FAILED ( hr ) )
    printf("Failed retrieving CAStoreFlags - %x\n", hr );
else
    printf("CAStoreFlags is %x\n", dwFlags );

// set the flag
hr = pEnroll->put_CAStoreFlags( CERT_SYSTEM_STORE_LOCAL_MACHINE );
if ( FAILED ( hr ) )
    printf("Failed updating CAStoreFlags - %x\n", hr );
else
    printf("Updated CAStoreFlags\n");
```