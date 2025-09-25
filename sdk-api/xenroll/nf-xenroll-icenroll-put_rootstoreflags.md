# ICEnroll::put_RootStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RootStoreFlags** property sets or retrieves the registry location used for the root store.

The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **RootStoreFlags** property value is passed to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) CryptoAPI function by using its *dwFlags* parameter.

The **RootStoreFlags** property should be set before using the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
DWORD    dwFlags;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer.

// Retrieve the flag value.
hr = pEnroll->get_RootStoreFlags( &dwFlags );
if ( FAILED ( hr ) )
    printf("Failed retrieving RootStoreFlags - %x\n", hr );
else
    printf("RootStoreFlags is %x\n", dwFlags );

// Set the flag.
hr = pEnroll->put_RootStoreFlags( CERT_SYSTEM_STORE_LOCAL_MACHINE );
if ( FAILED ( hr ) )
    printf("Failed updating RootStoreFlags - %x\n", hr );
else
    printf("Updated RootStoreFlags\n");
```