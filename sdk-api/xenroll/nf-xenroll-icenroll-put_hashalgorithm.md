# ICEnroll::put_HashAlgorithm

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **HashAlgorithm** property sets or retrieves only the signature [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) used to sign the PKCS #10 certification request.

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

This signature [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) is not to be confused with the *hashing algorithm* used to sign the certificate. The enrollment control currently supports any [OID](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) for *hashing algorithms*, plus the following display name values: SHA1 (the default), MD2, and MD5. When retrieving this property, the retrieved value is in OID format (that is, SHA1 appears as 1.3.14.3.2.29). When setting this property, the corresponding OID format can be used as an alternative to the text shown for the defined friendly values.

The Certificate Enrollment Control considers the value of the **HashAlgorithm** property as a hint to the [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) to use for signing the PKCS #10 certification request. If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) supports the algorithm specified in the **HashAlgorithm** property, the algorithm will be used. Otherwise, the Certificate Enrollment Control will try to use SHA1. If SHA1 is not supported by the CSP, then MD5 will be tried. If neither SHA1 nor MD5 is supported, the Certificate Enrollment Control will try to use the first *hashing algorithm* returned from the CSP.

The **HashAlgorithm** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)

If both the
[HashAlgID](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-get_hashalgid) and **HashAlgorithm** properties are set, whichever is last updated will specify which [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) will be used to sign the PKCS #10 certification request.

#### Examples

```cpp
BSTR     bstrHashAlg = NULL;
HRESULT  hr;

// get the hash algorithm
hr = pEnroll->get_HashAlgorithm( &bstrHashAlg );
if ( FAILED ( hr ) )
    printf("Failed get_HashAlgorithm - %x\n", hr );
else
    printf( "HashAlgorithm: %ws\n", bstrHashAlg );
// free BSTR
if ( NULL != bstrHashAlg )
    SysFreeString( bstrHashAlg);

BSTR    bstrMyHashAlg = SysAllocString(TEXT("MD5"));
// alternatively, ... = SysAllocString(TEXT("1.2.840.113549.1.1.4"));

// set the hash algorithm
hr = pEnroll->put_HashAlgorithm( bstrMyHashAlg );
if ( FAILED ( hr ) )
    printf("Failed put_HashAlgorithm - %x\n", hr );
else
    printf( "HashAlgorithm was set to %ws\n", bstrMyHashAlg );
// free BSTR
if ( NULL != bstrMyHashAlg )
    SysFreeString( bstrMyHashAlg);
```