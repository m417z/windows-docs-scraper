# ICEnroll::put_RootStoreName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **RootStoreName** property sets or retrieves the name of the root store where all intrinsically trusted, self-signed [root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) are kept.

 The default value for this property is "ROOT". Because of the level of trust associated with the root store, the user may be prompted (by means of the user interface) to accept the certificate. Although this property need not be changed for many applications, to avoid the user interface associated with trusting [root certificates](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), a possibility is to set **RootStoreName** to "CA".

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

**RootStoreName** affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR     bstrStoreName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the storename
hr = pEnroll->get_RootStoreName( &bstrStoreName );
if ( FAILED ( hr ) )
    printf("Failed getting RootStoreName - %x\n", hr );
else
    printf( "RootStoreName: %ws\n", bstrStoreName );
// free BSTR when done
if ( NULL != bstrStoreName )
    SysFreeString( bstrStoreName );

// set the storename
// bstrNewName is a BSTR that is previously set to a valid store name
hr = pEnroll->put_RootStoreName( bstrNewName );
if ( FAILED ( hr ) )
    printf("Failed setting RootStoreName - %x\n", hr );
else
    printf( "RootStoreName was set to : %ws\n", bstrNewName );
```