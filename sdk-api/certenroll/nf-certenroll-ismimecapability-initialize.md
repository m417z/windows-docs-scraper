# ISmimeCapability::Initialize

## Description

The **Initialize** method initializes the object from a symmetric encryption algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and an optional key length.

## Parameters

### `pObjectId` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the OID.

### `BitCount` [in]

A **LONG** variable that contains the bit length of the symmetric key.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) pointer is **NULL**. |

## Remarks

The following symmetric encryption algorithms are supported by the Certificate Enrollment API. Only the [RC2](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) and [RC4](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) algorithms have variable key lengths that can be specified.

| OID | Key length | Description |
| --- | --- | --- |
| XCN_OID_OIWSEC_desCBC1.3.14.3.2.7 | 56 | The key size is of the DES CBC algorithm is 56 bits. You do not need to specify this value. |
| XCN_OID_RSA_DES_EDE3_CBC1.2.840.113549.3.7 | 168 | The key size is of the 3DES CBC algorithm is 168 bits. You do not need to specify this value. |
| XCN_OID_RSA_RC2CBC1.2.840.113549.3.2 | 40 to 128 | RC4 is a variable key algorithm. common values are 40, 64, and 128 bits. |
| XCN_OID_RSA_RC41.2.840.113549.3.4 | 40 to 128 | RC4 is a variable key algorithm. common values are 40, 64, and 128 bits. |
| XCN_OID_RSA_SMIMEalgCMS3DESwrap1.2.840.113549.1.9.16.3.6 | 168 | The key size of the MMS [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES) key wrap algorithm is 168 bits. You do not need to specify this value. |
| XCN_OID_RSA_SMIMEalgCMSRC2wrap1.2.840.113549.1.9.16.3.7 | 128 | The key size of the MMS RC2 key wrap algorithm is 128 bits. You do not need to specify this value. |
| XCN_OID_NIST_AES128_CBC2.16.840.1.101.3.4.1.2 | 128 | The key size is implied by the OID. You do not need to specify this value. |
| XCN_OID_NIST_AES192_CBC2.16.840.1.101.3.4.1.22 | 192 | The key size is implied by the OID. You do not need to specify this value. |
| XCN_OID_NIST_AES256_CBC2.16.840.1.101.3.4.1.42 | 256 | The key size is implied by the OID. You do not need to specify this value. |
| XCN_OID_NIST_AES128_WRAP2.16.840.1.101.3.4.1.5 | 128 | The key size is implied by the OID. You do not need to specify this value. |
| XCN_OID_NIST_AES192_WRAP2.16.840.1.101.3.4.1.25 | 192 | The key size is implied by the OID. You do not need to specify this value. |
| XCN_OID_NIST_AES256_WRAP2.16.840.1.101.3.4.1.45 | 256 | The key size is implied by the OID. You do not need to specify this value. |

The key length that you specify for RC2 and RC4 algorithms must be consistent with that supported by the cryptographic provider or providers used by the client. For more information, see [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation). You can retrieve the bit length by calling the [BitCount](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ismimecapability-get_bitcount) property, and you can retrieve the algorithm OID by calling the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ismimecapability-get_objectid) property.

## See also

[ISmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapabilities)

[ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability)

[IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities)