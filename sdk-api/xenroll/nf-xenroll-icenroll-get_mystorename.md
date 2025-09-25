# ICEnroll::get_MyStoreName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **MyStoreName** property sets or retrieves the name of the store where certificates with linked [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) are kept.

The value of **MyStoreName** specifies the store in which to place the new certificate produced from
[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7) or
[acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7). The default value for this property is "MY". This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **MyStoreName** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storename
hr = pEnroll->get_MyStoreName( &bstrStoreName );
if ( FAILED ( hr ) )
    printf("Failed getting MyStoreName - %x\n", hr );
else
    printf( "MyStoreName: %ws\n", bstrStoreName );
// free BSTR when done
if ( NULL != bstrStoreName )
    SysFreeString( bstrStoreName );

// set the storename
// bstrNewName previously set to a valid store name
hr = pEnroll->put_MyStoreName( bstrNewName );
if ( FAILED ( hr ) )
    printf("Failed setting MyStoreName - %x\n", hr );
else
    printf( "MyStoreName was set to : %ws\n", bstrNewName );
```