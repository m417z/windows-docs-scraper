# ICEnroll::put_MyStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **MyStoreFlags** property sets or retrieves the registry location used for MY store.

The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **MyStoreFlags** property value is passed to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) CryptoAPI function by using its *dwFlags* parameter.

The **MyStoreFlags** property should be set before using the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
DWORD    dwFlags;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// retrieve the flag value
hr = pEnroll->get_MyStoreFlags( &dwFlags );
if ( FAILED ( hr ) )
    printf("Failed retrieving MyStoreFlags - %x\n", hr );
else
    printf("MyStoreFlags is %x\n", dwFlags );

// set the flag
hr = pEnroll->put_MyStoreFlags( CERT_SYSTEM_STORE_LOCAL_MACHINE );
if ( FAILED ( hr ) )
    printf("Failed updating MyStoreFlags - %x\n", hr );
else
    printf("Updated MyStoreFlags\n");
```