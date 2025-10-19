# ICspAlgorithm::GetAlgorithmOid

## Description

The **GetAlgorithmOid** method retrieves the algorithm object identifier (OID). This method is web enabled.

## Parameters

### `Length` [in]

A **LONG** variable that identifies the required key size of the symmetric encryption algorithm. Use this parameter to retrieve a specific AES algorithm from a Cryptography API: Next Generation (CNG) key storage provider (KSP). A KSP may list only one algorithm named AES but support all of the AES variants in the following list:

* szOID_NIST_AES128_CBC (2.16.840.1.101.3.4.1.2)
* szOID_NIST_AES192_CBC (2.16.840.1.101.3.4.1.22)
* szOID_NIST_AES256_CBC (2.16.840.1.101.3.4.1.42)
* szOID_NIST_AES128_WRAP (2.16.840.1.101.3.4.1.5)
* szOID_NIST_AES192_WRAP (2.16.840.1.101.3.4.1.25)
* szOID_NIST_AES256_WRAP (2.16.840.1.101.3.4.1.45)

 If you specify zero for the *Length* parameter and **AlgorithmFlagsNone** (0x00000000) for the *AlgFlags* parameter, the OID associated with the default algorithm is retrieved. For the Microsoft Software KSP and the Microsoft Smart Card KSP, the default AES algorithm is szOID_NIST_AES128_CBC (2.16.840.1.101.3.4.1.2).

**Note** This parameter must be zero for any algorithm other than a symmetric encryption algorithm.

### `AlgFlags` [in]

An [AlgorithmFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-algorithmflags) enumeration value that specifies whether to search for a key wrapping algorithm. This can be one of the following values:

* **AlgorithmFlagsNone**
* **AlgorithmFlagsWrap**

Specifying **AlgorithmFlagsWrap** causes this method to search for algorithms for which the display name ends with "wrap". This includes the following OIDs:

* szOID_NIST_AES128_WRAP (2.16.840.1.101.3.4.1.5)
* szOID_NIST_AES192_WRAP (2.16.840.1.101.3.4.1.25)
* szOID_NIST_AES256_WRAP (2.16.840.1.101.3.4.1.45)
* XCN_OID_RSA_SMIMEalgCMS3DESwrap (1.2.840.113549.1.9.16.3.6)
* XCN_OID_RSA_SMIMEalgCMSRC2wrap (1.2.840.113549.1.9.16.3.7)

 If you specify zero for the *Length* parameter and **AlgorithmFlagsNone** (0x00000000) for the *AlgFlags* parameter, the OID associated with the default algorithm is retrieved. For the Microsoft Software KSP and the Microsoft Smart Card KSP, the default AES algorithm is szOID_NIST_AES128_CBC (2.16.840.1.101.3.4.1.2).

**Note** This parameter must be zero for any algorithm other than a symmetric encryption algorithm.

### `ppValue` [out]

Address of a variable that receives a pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the algorithm OID.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The algorithm OID could not be found. |
| **OLE_E_BLANK** | The CSP information has not been initialized. For more information, see the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface. |

## Remarks

You must call the [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromname) method or the [InitializeFromType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromtype) method on the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface before calling **GetAlgorithmOid**.

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)