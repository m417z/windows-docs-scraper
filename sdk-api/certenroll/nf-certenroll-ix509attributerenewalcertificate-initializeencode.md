# IX509AttributeRenewalCertificate::InitializeEncode

## Description

The **InitializeEncode** method initializes the attribute by using the certificate to be renewed. The certificate must be encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER).

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the certificate contained in the *strCert* parameter.

### `strCert` [in]

A **BSTR** variable that contains the DER-encoded certificate.

Beginning with Windows 7 and Windows Server 2008 R2, you can specify a certificate thumb print or serial number rather than an encoded certificate. Doing so causes the function to search the appropriate local stores for the matching certificate. Keep in mind the following points:

* The **BSTR** must be an even number of hexadecimal digits.
* Whitespace between hexadecimal pairs is ignored.
* The *Encoding* parameter must be set to **XCN_CRYPT_STRING_HEXRAW**.
* If a private key is needed, only the personal and request stores are searched.
* If a private key is not needed, the root and intermediate CA stores are also searched.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for this attribute is **XCN_OID_RENEWAL_CERTIFICATE** (1.3.6.1.4.1.311.13.1). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributerenewalcertificate-initializedecode) before you can use an [IX509AttributeRenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributerenewalcertificate) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the [RenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributerenewalcertificate-get_renewalcertificate) property to retrieve the raw data.

## See also

[IX509AttributeRenewalCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributerenewalcertificate)