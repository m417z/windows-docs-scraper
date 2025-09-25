# IObjectId::InitializeFromAlgorithmName

## Description

The **InitializeFromAlgorithmName** method initializes the object from an algorithm name or an object identifier. This method has been provided primarily to enable you to initialize the object from a Cryptography API: Next Generation (CNG) algorithm name. You can, however, specify any OID name. This method is web enabled.

## Parameters

### `GroupId` [in]

An [ObjectIdGroupId](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-objectidgroupid) enumeration value that specifies the OID group to search. This can be any of the following algorithm groups:

* **XCN_CRYPT_HASH_ALG_OID_GROUP_ID**
* **XCN_CRYPT_ENCRYPT_ALG_OID_GROUP_ID**
* **XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID**
* **XCN_CRYPT_SIGN_ALG_OID_GROUP_ID**

In addition, you can also specify groups that do not contain cryptographic algorithms:

* **XCN_CRYPT_RDN_ATTR_OID_GROUP_ID**
* **XCN_CRYPT_EXT_OR_ATTR_OID_GROUP_ID**
* **XCN_CRYPT_ENHKEY_USAGE_OID_GROUP_ID**
* **XCN_CRYPT_POLICY_OID_GROUP_ID**
* **XCN_CRYPT_TEMPLATE_OID_GROUP_ID**

### `KeyFlags` [in]

An [ObjectIdPublicKeyFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-objectidpublickeyflags) enumeration value that specifies whether to search for a signing or an encryption algorithm. This can be one of the following values:

* **XCN_CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG**
* **XCN_CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG**

You can use either value to disambiguate among algorithms such as RSA that can be used to both encrypt and sign messages. You must also specify **XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID** in the *GroupId* parameter.

### `AlgFlags` [in]

An [AlgorithmFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmflags) enumeration value. This can be one of the following values:

* **AlgorithmFlagsNone**
* **AlgorithmFlagsWrap**

If you specify **XCN_CRYPT_ENCRYPT_ALG_OID_GROUP_ID** for the *GroupId* parameter, you can use the **AlgorithmFlags** enumeration to search for an OID that can be used to wrap a key. For example, you can retrieve information about the AES128wrap algorithm if you specify a bit length of 128 (see the Remarks section), set the *strAlgorithmName* parameter to AES, and specify **AlgorithmFlagsWrap**.

### `strAlgorithmName` [in]

A **BSTR** variable that contains the name. You can specify a name, or an OID in dotted decimal format. The method verifies that the format is consistent with the ASN.1 X.208 standard. For more information about CNG algorithm names, see [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The OID information could not be found. |
| ****CRYPT_E_UNKNOWN_ALGO**** | The algorithm name is not recognized. |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

You can use the upper 16 bits of the *GroupId* parameter to specify the key size for algorithms that accept a variable bit length. For example, to initialize an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object from a 192-bit AES algorithm, specify "AES" for the *strAlgorithmName* parameter, shift the length left by 16, and perform a bitwise-**OR** combination on the shifted bit length and the *GroupId* value.

## See also

[IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)