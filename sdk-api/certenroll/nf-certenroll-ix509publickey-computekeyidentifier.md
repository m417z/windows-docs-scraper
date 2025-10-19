# IX509PublicKey::ComputeKeyIdentifier

## Description

The **ComputeKeyIdentifier** method creates an identifier from a 160-bit SHA-1 hash of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `Algorithm` [in]

A value of the [KeyIdentifierHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-keyidentifierhashalgorithm) enumeration that specifies what hash algorithm to use to create the key identifier.

If this value is SKIHashDefault or SKIHashSha1, the identifier is created by hashing only the byte array that contains the key and excluding the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) tag, length, and unused bits fields.

If this value is SKIHashCapiSha1, the identifier is created by hashing the DER-encoded byte array that contains the tag, length, number of unused bits, and the public key.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding to be applied to the hash contained in the *pValue* parameter. The default value is XCN_CRYPT_STRING_BASE64.

### `pValue` [out]

Pointer to a **BSTR** variable that contains the key identifier.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The algorithm object identifier or the public key parameters could not be found. |

## Remarks

You must call the [InitializeFromEncodedPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-initializefromencodedpublickeyinfo) method or the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-initialize) method to initialize the public key object before calling **ComputeKeyIdentifier**.

## See also

[IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey)