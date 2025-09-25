# IX509PublicKey::Initialize

## Description

The **Initialize** method initializes the object from a public key algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and from byte arrays that contain a public key and the associated parameters, if any. The byte arrays are represented by Unicode-encoded strings.

## Parameters

### `pObjectId` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the algorithm OID.

### `strEncodedKey` [in]

A **BSTR** variable that contains the public key.

### `strEncodedParameters` [in]

A **BSTR** variable that contains the parameters associated with the public key. For more information, see the [EncodedParameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedparameters) property.

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode-encoding applied to the arguments specified in the *strEncodedKey* and *strEncodedParameters* parameters. The default value is XCN_CRYPT_STRING_BASE64.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object has already been initialized. |

## Remarks

The **Initialize** method initializes the following property values:

* [Algorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_algorithm)
* [EncodedKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedkey)
* [EncodedParameters](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_encodedparameters)
* [Length](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-get_length)

## See also

[IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey)