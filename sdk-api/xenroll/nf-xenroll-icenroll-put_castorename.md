# ICEnroll::put_CAStoreName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **CAStoreName** property sets or retrieves the name of the store where all non-"ROOT" and non-"MY" certificates are kept.

The default value for this property is "CA". This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **CAStoreName** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storename
hr = pEnroll->get_CAStoreName( &bstrStoreName );
if ( FAILED ( hr ) )
    printf("Failed getting CAStoreName - %x\n", hr );
else
    printf( "CAStoreName: %ws\n", bstrStoreName );
// free BSTR when done
if ( NULL != bstrStoreName )
    SysFreeString( bstrStoreName );

// set the storename
// bstrNewName previously set to a valid store name
hr = pEnroll->put_CAStoreName( bstrNewName );
if ( FAILED ( hr ) )
    printf("Failed setting CAStoreName - %x\n", hr );
else
    printf( "CAStoreName was set to : %ws\n", bstrNewName );
```