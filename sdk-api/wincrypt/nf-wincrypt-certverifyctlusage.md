# CertVerifyCTLUsage function

## Description

The **CertVerifyCTLUsage** function verifies that a subject is trusted for a specified usage by finding a signed and time-valid [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) with the usage identifiers that contain the subject. A certificate's subject can be identified by either its [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or any unique identifier such as the SHA1 [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the subject's certificate.

## Parameters

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types can be added in the future. For either current encoding type, use

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `dwSubjectType` [in]

If the *dwSubjectType* parameter is set to CTL_CERT_SUBJECT_TYPE, *pvSubject* points to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. The structure's **SubjectAlgorithm** member is examined to determine the representation of the subject's identity. Initially, only SHA1 and MD5 hashes are supported as values for **SubjectAlgorithm**. The appropriate hash property is obtained from the **CERT_CONTEXT** structure.

If the *dwSubjectType* parameter is set to CTL_ANY_SUBJECT_TYPE, *pvSubject* points to the
[CTL_ANY_SUBJECT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_any_subject_info) structure. The **SubjectAlgorithm** member of this structure must match the algorithm type of the CTL, and the **SubjectIdentifier** member must match one of the CTL entries.

If *dwSubjectType* is set to either preceding value, *dwEncodingType* is not used.

### `pvSubject` [in]

Value used in conjunction with the *dwSubjectType* parameter.

### `pSubjectUsage` [in]

A pointer to a
[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure used to specify the intended usage of the subject.

### `dwFlags` [in]

If the CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG is not set, a CTL whose time is no longer valid in one of the stores specified by **rghCtlStore** in
[CTL_VERIFY_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_para) can be replaced. When replaced, the CERT_VERIFY_UPDATED_CTL_FLAG is set in the **dwFlags** member of *pVerifyUsageStatus*. If this flag is set, an update will not be made, even if a time-valid, updated CTL is received for a CTL that is in the store and whose time is no longer valid.

If the CERT_VERIFY_TRUSTED_SIGNERS_FLAG is set, only the signer stores specified by **rghSignerStore** in
[CTL_VERIFY_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_para) are searched to find the signer. Otherwise, the signer stores provide additional sources to find the signer's certificate. For more information, see Remarks.

If CERT_VERIFY_NO_TIME_CHECK_FLAG is set, the CTLs are not checked for time validity. Otherwise, they are.

If CERT_VERIFY_ALLOW_MORE_USAGE_FLAG is set, the CTL can contain usage identifiers in addition to those specified by *pSubjectUsage*. Otherwise, the found CTL will contain no additional usage identifiers.

### `pVerifyUsagePara` [in, optional]

A pointer to a
[CTL_VERIFY_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_para) structure that specifies the stores to be searched to find the CTL and the stores that contain acceptable CTL signers. Setting the **ListIdentifier** member further limits the search.

### `pVerifyUsageStatus` [in, out]

A pointer to a
[CTL_VERIFY_USAGE_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_status) structure. The **cbSize** member of the structure must to be set to the size, in bytes, of the structure, and all other fields must be set to zero before **CertVerifyCTLUsage** is called. For more information, see
**CTL_VERIFY_USAGE_STATUS**.

## Return value

If the subject is trusted for the specified usage, **TRUE** is returned. Otherwise, **FALSE** is returned. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can return one of the following error codes.

| Value | Description |
| --- | --- |
| **CRYPT_E_NO_VERIFY_USAGE_DLL** | No DLL or exported function was found to verify subject usage. |
| **CRYPT_E_NO_VERIFY_USAGE_CHECK** | The called function was not able to do a usage check on the subject. |
| **CRYPT_E_VERIFY_USAGE_OFFLINE** | The server was offline; therefore, the called function could not complete the usage check. |
| **CRYPT_E_NOT_IN_CTL** | The subject was not found in a CTL. |
| **CRYPT_E_NO_TRUSTED_SIGNER** | No trusted signer was found to verify the signature of the message or trust list. |

The **dwError** member of the [CTL_VERIFY_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_para) pointed to by *pVerifyUsageStatus* is set to the same error code.

## Remarks

**CertVerifyCTLUsage** is a dispatcher to functions that can be installed by using an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). First, it tries to find an OID function that matches the first usage object identifier in the [CLT_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure pointed to by *pSubjectUsage*. If this fails, it uses the default **CertDllVerifyCTLUsage** functions.

The **CertDllVerifyCTLUsage** function in Cryptnet.dll can be installed by using an OID; it has the following properties:

* If CTL stores are specified by **rghCtlStore** in *pVerifyUsagePara*, only those stores are searched to find a CTL. Otherwise, the Trust system store is searched to find a CTL.
* If CERT_VERIFY_TRUSTED_SIGNERS_FLAG is set, only the signer stores specified by **rghSignerStore** in *pVerifyUsagePara* are searched to find the certificate that corresponds to the signer's issuer and serial number. Otherwise, the CTL message's store, the signer stores specified by **rghSignerStore** in *pVerifyUsagePara*, the Trust system store, CA system store, ROOT, and [Software Publisher Certificate](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPC) system stores are searched to find the signer's certificate. In either case, the public key in the found certificate is used to verify the signature of the [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).
* If the CTL has a set **NextUpdate** member and CERT_VERIFY_NO_TIME_CHECK is not set, it is verified for time validity.
* If the CTL obtained from the store has a time that is not valid, an attempt is made to get a time-valid version. The **CertDllVerifyCTLUsage** function uses the **NextUpdateLocation** property or the **NextUpdateLocation** extension of the CTL, or it searches the signer's information for a **NextUpdateLocation** attribute.

## See also

[CTL_VERIFY_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_para)

[CTL_VERIFY_USAGE_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_verify_usage_status)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl)

[Verification Functions Using CTLs](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)