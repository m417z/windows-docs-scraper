# IObjectId::GetAlgorithmName

## Description

The **GetAlgorithmName** method retrieves the display name associated with an algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

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

* **XCN_CRYPT_OID_INFO_PUBKEY_ANY**
* **XCN_CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG**
* **XCN_CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG**

You can use either of the last two values to disambiguate among algorithms such as RSA that can be used to both encrypt and sign messages. You must also specify **XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID** in the *GroupId* parameter. Specify **XCN_CRYPT_OID_INFO_PUBKEY_ANY** if you set the *GroupId* parameter to anything other than **XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID**.

### `pstrAlgorithmName` [out]

Pointer to a **BSTR** variable that contains the name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****CERTSRV_E_PROPERTY_EMPTY**** | The string that contains the algorithm name is empty. |
| ****OLE_E_BLANK**** | The algorithm name could not be found. You must call [InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname) before calling [GetAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-getalgorithmname). |

## Remarks

You can use the **XCN_CRYPT_ENCRYPT_ALG_OID_GROUP_ID** constant to create a *GroupId* parameter value that takes account of the key size for algorithms that can be identified by a variable bit length. For example, to initialize an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object from a 192-bit AES algorithm, specify "AES" for the *strAlgorithmName* parameter, shift the length left by 16, and perform a bitwise-OR combination on the shifted bit length and **XCN_CRYPT_ENCRYPT_ALG_OID_GROUP_ID**.

If you set the *GroupId* parameter to anything other than **XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID**, specify **XCN_CRYPT_OID_INFO_PUBKEY_ANY** for the *KeyFlags* parameter.

## See also

[IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)