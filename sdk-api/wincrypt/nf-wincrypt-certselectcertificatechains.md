# CertSelectCertificateChains function

## Description

The **CertSelectCertificateChains** function retrieves certificate chains based on specified selection criteria.

## Parameters

### `pSelectionContext` [in, optional]

A pointer to the GUID of the certificate selection scenario to use for this call.

### `dwFlags` [in]

Flags for controlling the certificate selection process. This parameter can be a combination of zero or more of the following flags:

| Value | Meaning |
| --- | --- |
| **CERT_SELECT_ALLOW_EXPIRED** | Select expired certificates that meet selection criteria. By default expired certificates are rejected from selection. |
| **CERT_SELECT_TRUSTED_ROOT** | Select certificates on which the error bit in the certificate chain trust status is not set to **CERT_TRUST_IS_UNTRUSTED_ROOT**, **CERT_TRUST_IS_PARTIAL_CHAIN**, or **CERT_TRUST_IS_NOT_TIME_VALID**. <br><br>In addition, certificates that have one of the following invalid constraint errors are not selected:<br><br>* **CERT_TRUST_INVALID_POLICY_CONSTRAINTS**<br>* **CERT_TRUST_INVALID_BASIC_CONSTRAINTS**<br>* **CERT_TRUST_INVALID_NAME_CONSTRAINTS** |
| **CERT_SELECT_DISALLOW_SELFSIGNED** | Select certificates that are not self-issued and self-signed. |
| **CERT_SELECT_HAS_PRIVATE_KEY** | Select certificates that have a value set for the **CERT_KEY_PROV_INFO_PROP_ID** property of the certificate. |
| **CERT_SELECT_HAS_KEY_FOR_SIGNATURE** | Select certificates on which the value of the **dwKeySpec** member of the **CERT_KEY_PROV_INFO_PROP_ID** property is set to **AT_SIGNATURE**. <br><br>If this function is being called as part of a CNG enabled application and the **dwKeySpec** member of the **CERT_KEY_PROV_INFO_PROP_ID** property is set to -1, select certificates on which the value of the **NCRYPT_KEY_USAGE_PROPERTY** property of the associated private key has the **NCRYPT_ALLOW_SIGNING_FLAG** set. |
| **CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE** | Select certificates on which the value of the **dwKeySpec** member of the **CERT_KEY_PROV_INFO_PROP_ID** property is set to **AT_KEYEXCHANGE**. <br><br>If this function is being called as part of a CNG enabled application and the **dwKeySpec** member of the **CERT_KEY_PROV_INFO_PROP_ID** property is set to -1, select certificates on which either **NCRYPT_ALLOW_DECRYPT_FLAG** or **NCRYPT_ALLOW_KEY_AGREEMENT_FLAG** is set. |
| **CERT_SELECT_HARDWARE_ONLY** | Select certificates on which the value of the **PP_IMPTYPE** property of the associated private key provider is set to either  **CRYPT_IMPL_HARDWARE** or **CRYPT_IMPL_REMOVABLE**. (For CNG providers, NCRYPT_IMPL_TYPE_PROPERTY property value MUST have either the NCRYPT_IMPL_HARDWARE_FLAG or NCRYPT_IMPL_REMOVABLE_FLAG bit set).<br><br>If this function is being called as part of a CNG enabled application, select certificates on which the **NCRYPT_IMPL_TYPE_PROPERTY** property is set to  **NCRYPT_IMPL_HARDWARE_FLAG** or **NCRYPT_IMPL_REMOVABLE_FLAG**. |
| **CERT_SELECT_ALLOW_DUPLICATES** | Allow the selection of certificates on which the Subject and Subject Alt Name contain the same information and the certificate template extension value is equivalent. By default when certificates match this criteria, only the most recent certificate is selected. |

### `pChainParameters` [in, optional]

A pointer to a [CERT_SELECT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_chain_para) structure to specify parameters for chain building. If **NULL**, default parameters will be used.

The **pChainPara** member of the [CERT_SELECT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_chain_para) structure points to a [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure that can be used to enable strong signing.

### `cCriteria` [in]

The number of elements in the array pointed to by the *rgpCriteria* array.

### `rgpCriteria` [in, optional]

A pointer to an array of [CERT_SELECT_CRITERIA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_criteria) structures that define the selection criteria. If this parameter is set to **NULL**, the value of the *cCriteria* parameter must be zero.

### `hStore` [in]

The handle to a store from which to select the certificates.

### `pcSelection` [out]

 A pointer to a **DWORD** value to receive the number of elements in the array pointed to by the *pprgpSelection* parameter.

### `pprgpSelection` [out]

A pointer to a pointer to a location to receive an array of [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure. The **CertSelectCertificateChains** function only returns certificate chains that match all the selection criteria. The entries in the array are ordered by quality, i.e. the chain with the highest quality is the first entry.

Storage for the array is allocated by the **CertSelectCertificateChains** function. To free the allocated memory you must first release each individual chain context in the array by calling the [CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain) function. Then you must free the memory by calling the [CertFreeCertificateChainList](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechainlist) function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns zero (FALSE). For extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Note** If the selection does not yield any results, the **CertSelectCertificateChains** function returns **TRUE**, but the value pointed to by *pcSelection* parameter is set to zero.

## Remarks

Selection criteria can be specified through either the *dwFlags* parameter, through the *rgpCriteria* parameter, or through both parameters. If no selection criteria are specified, the function succeeds and returns certificate chains for all certificates in the store specified by the *hStore* parameter.

Certificate chains that are selected are ordered based on the following preference logic:

* Prefer certificates that are smart card certificates over certificates that are not smart-card based.
* Prefer certificates that have a longer validity period (the expiration date is later.)
* If multiple certificates have same expiration date, prefer certificates that were issued more recently.
* If there is a tie, prefer shorter chains.

Certain selection criteria require that a certificate chain be built before you can select that criteria for use. If the intermediate certificates required to build the chain are not available locally, a network retrieval is performed for the issuer certificates. This network retrieval is performed if the **CERT_SELECT_TRUSTED_ROOT** flag is set or for the following criteria:

* **CERT_SELECT_BY_ISSUER_NAME**
* **CERT_SELECT_BY_ISSUER_ATTR**
* **CERT_SELECT_BY_POLICY_OID**

Perform the following actions to enable strong signature checking:

* Create a [CERT_STRONG_SIGN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_para) structure, specify the required strong signing parameters, and set a pointer to the structure in the **pStrongSignPara** member of a [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure.
* Set a pointer to the [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure in the **pChainPara** member of a [CERT_SELECT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_chain_para) structure.
* Set a pointer to the [CERT_SELECT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_chain_para) structure in the *pChainParameters* parameter of this (**CertSelectCertificateChains**)function.

When you enable strong signature checking, any certificate chain that returns a **CERT_TRUST_IS_NOT_SIGNATURE_VALID** error in the **dwErrorStatus** field of the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure will be skipped. (The *pprgpSelection* parameter points to a [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure which, in turn, points to the **CERT_TRUST_STATUS** structure.) The **CERT_TRUST_HAS_WEAK_SIGNATURE** value is also set for a weak signature.

## See also

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)