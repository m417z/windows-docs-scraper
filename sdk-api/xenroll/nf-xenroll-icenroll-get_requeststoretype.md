# ICEnroll::get_RequestStoreType

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RequestStoreType** property sets or retrieves the type of store to use for the store specified by the
[RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename) property. This store type is passed directly to the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function.

The default value of this property is sz_CERT_STORE_PROV_SYSTEM. If the default is not to be used, this property must be set to the same value before calls to
[createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)/[createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10) and again before calls to
[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)/[acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7).

Only system stores are supported. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

Typically, modification of the **RequestStoreType** property is performed only in advanced applications.

**RequestStoreType** affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)
* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreType = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storetype
hr = pEnroll->get_RequestStoreType( &bstrStoreType );
if ( FAILED ( hr ) )
    printf("Failed getting RequestStoreType - %x\n", hr );
else
    printf( "RequestStoreType: %ws\n", bstrStoreType );
// free BSTR when done
if ( NULL != bstrStoreType )
    SysFreeString( bstrStoreType );

// set the storetype
// bstrNewType is a BSTR that is previously set to a valid store type
hr = pEnroll->put_RequestStoreType( bstrNewType );
if ( FAILED ( hr ) )
    printf("Failed setting RequestStoreType - %x\n", hr );
else
    printf( "RequestStoreType was set to %ws\n", bstrNewType );
```