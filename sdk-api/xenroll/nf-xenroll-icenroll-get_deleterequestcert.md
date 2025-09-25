# ICEnroll::get_DeleteRequestCert

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **DeleteRequestCert** property sets or retrieves a Boolean value that determines whether dummy certificates in the request store are deleted.

Dummy certificates are created for the purpose of persisting the keys generated for the PKCS #10 request during the enrollment process. The store specified by the
[RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename) property is where the dummy certificate is created. The newly generated keys are added as properties to the dummy certificate to persist them until a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) processes the request and responds with a PKCS #7. On acceptance of the PKCS #7, the dummy certificate is removed and the keys are added as properties of the issued certificate returned by the certification authority. For debugging and testing, it is often desirable to not delete the dummy certificate. Setting the **DeleteRequestCert** property to **FALSE** prevents its deletion.

The default value for this property is **TRUE**. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **DeleteRequestCert** property affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
BOOL     bDRC;
HRESULT  hr;

// pEnroll is a previously instantiated ICEnroll interface pointer.
// Get the DeleteRequestCert Boolean value.

hr = pEnroll->get_DeleteRequestCert( &bDRC );
if ( FAILED ( hr ) )
    printf("Failed getting DeleteRequestCert - %x\n", hr );
else
    printf( "DeleteRequestCert: %s\n", ( bDRC ? "TRUE" : "FALSE" ) );

// Set the DeleteRequestCert value.

hr = pEnroll->put_DeleteRequestCert( FALSE );
if ( FAILED ( hr ) )
    printf("Failed Setting DeleteRequestCert - %x\n", hr );
else
    printf( "DeleteRequestCert was set to FALSE\n" );
```