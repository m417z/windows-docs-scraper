# ICEnroll::get_RequestStoreName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RequestStoreName** property sets or retrieves[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) the name of the store that contains the dummy certificate. This dummy certificate, along with the added private keys, remains in the request store until a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) processes the request and responds with a PKCS #7.

The default value for this property is "REQUEST". If the default is not to be used, this property must be set to the store to be used before calls to
[createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10) or [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10) and again before calls to
[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7) or [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7).

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

Typically, modification of the **RequestStoreName** property is performed only in advanced applications. Changing this value is not recommended for most applications.

The **RequestStoreName** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)
* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storename
hr = pEnroll->get_RequestStoreName( &bstrStoreName );
if ( FAILED ( hr ) )
    printf("Failed getting RequestStoreName - %x\n", hr );
else
    printf( "RequestStoreName: %ws\n", bstrStoreName );
// free BSTR when done
if ( NULL != bstrStoreName )
    SysFreeString( bstrStoreName );

// set the storename
// bstrNewName is a BSTR that is previously set to a valid store name
hr = pEnroll->put_RequestStoreName( bstrNewName );
if ( FAILED ( hr ) )
    printf("Failed setting RequestStoreName - %x\n", hr );
else
    printf( "RequestStoreName was set to : %ws\n", bstrNewName );
```