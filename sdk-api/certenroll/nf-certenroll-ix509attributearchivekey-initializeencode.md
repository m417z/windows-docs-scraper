# IX509AttributeArchiveKey::InitializeEncode

## Description

The **InitializeEncode** method initializes the attribute from an [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object, the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) encryption certificate, and the symmetric encryption algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Parameters

### `pKey` [in]

Pointer to an [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface that represents the key.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the input string that contains the encrypted key.

### `strCAXCert` [in]

A **BSTR** variable that contains the certification authority encryption certificate that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to encrypt the private key.

Beginning with Windows 7 and Windows Server 2008 R2, you can specify a certificate thumb print or serial number rather than an encoded certificate. Doing so causes the function to search the appropriate local stores for the matching certificate. Keep in mind the following points:

* The **BSTR** must be an even number of hexadecimal digits.
* Whitespace between hexadecimal pairs is ignored.
* The *Encoding* parameter must be set to **XCN_CRYPT_STRING_HEXRAW**.
* Only the personal and request stores are searched for the private key.

### `pAlgorithm` [in, optional]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the OID of the symmetric encryption algorithm used to encrypt the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This parameter is optional. If you do not supply an OID, XCN_OID_RSA_DES_EDE3_CBC (Triple DES) is used.

### `EncryptionStrength` [in]

A **LONG** variable that contains the encryption strength of the algorithm identified by the *pAlgorithm* parameter. This parameter is not currently used because the Certificate Enrollment SDK does not support any algorithms for which the OID does not already imply the strength (key length). For example, AES has multiple strengths but strength each is already indicated by the OID.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The object identifier for this attribute is **XCN_OID_ARCHIVED_KEY_ATTR** (1.3.6.1.4.1.311.21.13). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializedecode) before you can use an [IX509AttributeArchiveKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekey) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the following properties to retrieve the raw data:

* [EncryptionAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionalgorithm)
* [EncryptedKeyBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptedkeyblob)
* [EncryptionStrength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionstrength)

## See also

[IX509AttributeArchiveKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekey)