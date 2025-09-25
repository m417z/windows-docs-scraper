# IX509AttributeCspProvider::InitializeEncode

## Description

The **InitializeEncode** method initializes the attribute from information about the provider.

## Parameters

### `KeySpec` [in]

An [X509KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyspec) enumeration value that identifies whether the key pair is used for encryption or for signing.

### `strProviderName` [in]

A **BSTR** variable that contains the provider name.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the signature contained in the *strSignature* parameter.

### `strSignature` [in]

A **BSTR** variable that contains the provider signature.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for this attribute is **XCN_OID_ENROLLMENT_CSP_PROVIDER** (1.3.6.1.4.1.311.13.2.2). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-initializedecode) before you can use an [IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the following properties to retrieve the raw data:

* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_keyspec)
* [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_providername)
* [Signature](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_signature)

## See also

[IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider)