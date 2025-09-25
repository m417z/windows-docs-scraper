# ICEnroll3::put_HashAlgID

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **HashAlgID** property sets or retrieves the [hash algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used when signing a PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

This property was first introduced in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

This property is read/write.

## Parameters

## Remarks

The values for this property are [hash algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) IDs, such as those returned by the
[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-enumalgs) method. If both the **HashAlgID** and
[HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_hashalgorithm) properties are set, whichever has been updated most recently determines the hash algorithm used to sign the PKCS #10 request.

#### Examples

```cpp
// Code to set the hash algorithm ID.
// hr is HRESULT variable.
hr = pEnroll->put_HashAlgID( CALG_MD4 );
if ( FAILED( hr ) )
    printf("Failed put_HashAlgID [%x]\n", hr);

// Code to retrieve the hash algorithm ID.
DWORD dwHashID;

hr = pEnroll->get_HashAlgID( &dwHashID );
if ( FAILED( hr ) )
    printf("Failed get_HashAlgID [%x]\n", hr);
else
    printf("HashAlgID: %d\n", dwHashID);
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-enumalgs)

[HashAlgorithm](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_hashalgorithm)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)