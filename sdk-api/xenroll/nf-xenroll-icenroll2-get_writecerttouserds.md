# ICEnroll2::get_WriteCertToUserDS

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WriteCertToUserDS** property sets or retrieves a Boolean value that determines whether the certificate is written to the user's Active Directory store.

 This property should not need to be modified by most applications. This property was first defined in the [ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2) interface.

This property is read/write.

## Parameters

## Remarks

**WriteCertToUserDS** affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

The ability to set this property is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BOOL     bWriteUserDS;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll2 interface pointer

// get the WriteCertToUserDS value
hr = pEnroll->get_WriteCertToUserDS( &bWriteUserDS );
if (FAILED( hr ))
    printf("Failed get_WriteCertToUserDS - %x\n", hr );
else
    printf( "WriteCertToUserDS: %d\n", bWriteUserDS );

// set the WriteCertToUserDS value
hr = pEnroll->put_WriteCertToUserDS( TRUE );
if (FAILED( hr ))
    printf("Failed put_WriteCertToUserDS - %x\n", hr );
else
    printf( "WriteCertToUserDS set to TRUE\n" );
```