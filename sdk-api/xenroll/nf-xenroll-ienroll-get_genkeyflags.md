# IEnroll::get_GenKeyFlags

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GenKeyFlags** property sets or retrieves the values passed to [CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) when the certificate request is generated.

By default, the **GenKeyFlags** property is set to zero. However, when a .pvk file is specified, the value of **GenKeyFlags** defaults to CRYPT_EXPORTABLE. For more information, see Remarks.

This property was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

This property is read/write.

## Parameters

## Remarks

By default, private keys are not exportable unless a .pvk file is requested. To make the private key exportable without specifying a .pvk file, set **GenKeyFlags** to CRYPT_EXPORTABLE.

To specify a .pvk file name, use the
[PVKFileNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_pvkfilenamewstr) property.

The **GenKeyFlags** property value is passed to the
[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey) CryptoAPI function by using its *dwFlags* parameter.

If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) does not support exportable private keys, an error occurs.

The **GenKeyFlags** property affects the behavior of the following methods:

* [createPKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createpkcs10wstr)
* [createFilePKCS10WStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-createfilepkcs10wstr)
* [createRequestWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll4-createrequestwstr)

**Note** The default value for the **GenKeyFlags** property is zero. If you need to change this value, you must do so before calling these methods. After calling any of these methods, you cannot change the **GenKeyFlags** property value.

## See also

[CryptGenKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenkey)

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)