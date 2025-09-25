# ICEnroll::put_CAStoreType

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CAStoreType** property sets or retrieves the type of store to use for the store specified by the
[CAStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_castorename) property. This store type is passed directly on to the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function.

The default value for this property is sz_CERT_STORE_PROV_SYSTEM. Only system stores are supported. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **CAStoreType** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreType = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storetype
hr = pEnroll->get_CAStoreType( &bstrStoreType );
if ( FAILED ( hr ) )
    printf("Failed getting CAStoreType - %x\n", hr );
else
    printf( "CAStoreType: %ws\n", bstrStoreType );
// free BSTR when done
if ( NULL != bstrStoreType )
    SysFreeString( bstrStoreType );

// set the storetype
// bstrNewType previously set to a valid store type
hr = pEnroll->put_CAStoreType( bstrNewType );
if ( FAILED ( hr ) )
    printf("Failed setting CAStoreType - %x\n", hr );
else
    printf( "CAStoreType was set to %ws\n", bstrNewType );
```