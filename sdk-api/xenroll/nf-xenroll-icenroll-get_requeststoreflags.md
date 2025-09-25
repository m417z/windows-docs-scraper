# ICEnroll::get_RequestStoreFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RequestStoreFlags** property sets or retrieves the registry location used for the request store.

 The default value for this property is CERT_SYSTEM_STORE_CURRENT_USER. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **RequestStoreFlags** property value is passed to the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) CryptoAPI function by using its *dwFlags* parameter.

Typically, modification of the **RequestStoreFlags** property is performed only in advanced applications.

The **RequestStoreFlags** property should be set before using the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)
* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
DWORD    dwFlags;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// retrieve the flag value
hr = pEnroll->get_RequestStoreFlags( &dwFlags );
if ( FAILED ( hr ) )
    printf("Failed retrieving RequestStoreFlags - %x\n", hr );
else
    printf("RequestStoreFlags is %x\n", dwFlags );

// set the flag
hr = pEnroll->put_RequestStoreFlags
   ( CERT_SYSTEM_STORE_LOCAL_MACHINE );
if ( FAILED ( hr ) )
    printf("Failed updating RequestStoreFlags - %x\n", hr );
else
    printf("Updated RequestStoreFlags\n");
```