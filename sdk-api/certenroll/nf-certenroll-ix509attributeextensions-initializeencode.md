# IX509AttributeExtensions::InitializeEncode

## Description

The **InitializeEncode** method initializes the object from an [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) collection.

## Parameters

### `pExtensions` [in]

Pointer to an [IX509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensions) interface that contains the collection.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) for this attribute is **XCN_OID_RSA_certExtensions** (1.2.840.113549.1.9.14). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeextensions-initializedecode) before you can use an [IX509AttributeExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeextensions) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure that contains the certificate extensions. You can call the [X509Extensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeextensions-get_x509extensions) property to retrieve the extensions.

## See also

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509AttributeExtensions](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeextensions)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)