# ICEnroll2::get_EnableT61DNEncoding

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **EnableT61DNEncoding** property sets or retrieves a Boolean value that determines whether the distinguished name in the request is encoded as a T61 string instead of as a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

 A T61 character is 8 bits, hence all Unicode characters to be encoded must be less than or equal to 0xFF. This property was first defined in the [ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2) interface.

This property is read/write.

## Parameters

## Remarks

The **EnableT61DNEncoding** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

#### Examples

```cpp
BOOL     bT61DN;
HRESULT  hr;

// pEnroll is a previously instantiated ICEnroll2 interface pointer.
// Get the EnableT61DNEncoding Boolean value.

hr = pEnroll->get_EnableT61DNEncoding( &bT61DN );
if ( FAILED ( hr ) )
    printf("Failed get_EnableT61DNEncoding - %x\n", hr );
else
    printf( "T61DNEncoding: %s\n",
             ( bT61DN ? "Enabled" : "Disabled" ) );

// Set the EnableT61DNEncoding value.

hr = pEnroll->put_EnableT61DNEncoding( TRUE );
if ( FAILED ( hr ) )
    printf("Failed Setting EnableT61DNEncoding - %x\n", hr );
else
    printf( "EnableT61DNEncoding was set to TRUE\n" );
```