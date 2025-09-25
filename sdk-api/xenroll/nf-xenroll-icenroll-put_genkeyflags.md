# ICEnroll::put_GenKeyFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GenKeyFlags** property sets or retrieves the values passed to the [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) function when the certificate request is generated.

By default, the **GenKeyFlags** property is set to zero. However, when a .pvk file is specified, the value of **GenKeyFlags** defaults to CRYPT_EXPORTABLE. For more information, see Remarks.

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

By default, private keys are not exportable unless a .pvk file is requested. To make the private key exportable without specifying a .pvk file, set **GenKeyFlags** to CRYPT_EXPORTABLE.

To specify a .pvk file name, use the
[PVKFileName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_pvkfilename) property.

The **GenKeyFlags** property value is passed to the
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) CryptoAPI function by using its *dwFlags* parameter.

If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) does not support exportable private keys, an error occurs.

The **GenKeyFlags** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)
* [createRequest](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll4-createrequest)

**Note** The default value for the **GenKeyFlags** property is zero. If you need to change this value, you must do so before calling these methods. After calling any of these methods, you cannot change the **GenKeyFlags** property value.

#### Examples

```cpp
LONG     lGenKey;
HRESULT  hr;

// pEnroll is a previously instantiated ICEnroll interface pointer.

// Get the GenKeyFlags value.
hr = pEnroll->get_GenKeyFlags( &lGenKey );
if (FAILED( hr ))
    printf("Failed get_GenKeyFlags - %x\n", hr );
else
    printf( "GenKeyFlags: %d\n", lGenKey );

// Set the GenKeyFlags value.
hr = pEnroll->put_GenKeyFlags( CRYPT_EXPORTABLE );
if (FAILED( hr ))
    printf("Failed put_GenKeyFlags - %x\n", hr );
else
    printf( "GenKeyFlags set to %d\n", CRYPT_EXPORTABLE );
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll)

[ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)