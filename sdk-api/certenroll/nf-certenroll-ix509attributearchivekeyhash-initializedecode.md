# IX509AttributeArchiveKeyHash::InitializeDecode

## Description

The **InitializeDecode** method initializes the object from a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded byte array that contains a SHA-1 [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the encrypted [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The byte array is represented by a Unicode-encoded string.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains hash value.

### `strEncodedData` [in]

A **BSTR** variable that contains the DER-encoded attribute.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for this attribute is **XCN_OID_ENCRYPTED_KEY_HASH** (1.3.6.1.4.1.311.21.21). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You can use this method if you have a DER-encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) object that contains the attribute value. You must supply the DER-encoded object in a Unicode encoded string. For more information, see the [IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter) interface.

You must call either [InitializeEncodeFromEncryptedKeyBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekeyhash-initializeencodefromencryptedkeyblob) or **InitializeDecode** before you can use an [IX509AttributeArchiveKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekeyhash) object. The two methods complement each other. The **InitializeEncodeFromEncryptedKeyBlob** method enables you to construct an encoded ASN.1 structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the [EncryptedKeyHashBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekeyhash-get_encryptedkeyhashblob) property to retrieve the raw data.

## See also

[IX509AttributeArchiveKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekeyhash)