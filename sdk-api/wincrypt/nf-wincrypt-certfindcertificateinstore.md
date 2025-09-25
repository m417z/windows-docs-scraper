# CertFindCertificateInStore function

## Description

The **CertFindCertificateInStore** function finds the first or next certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that matches a search criteria established by the *dwFindType* and its associated *pvFindPara*. This function can be used in a loop to find all of the [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that match the specified find criteria.

## Parameters

### `hCertStore` [in]

A handle of the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be searched.

### `dwCertEncodingType` [in]

Specifies the type of encoding used. Both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) must be specified by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwFindFlags` [in]

Used with some *dwFindType* values to modify the search criteria. For most *dwFindType* values, *dwFindFlags* is not used and should be set to zero. For detailed information, see Remarks.

### `dwFindType` [in]

Specifies the type of search being made. The search type determines the data type, contents, and the use of *pvFindPara*. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_FIND_ANY** | Data type of *pvFindPara*: **NULL**, not used.<br><br>No search criteria used. Returns the next certificate in the store.<br><br>**Note** The order of the certificate context may not be preserved within the store. To access a specific certificate you must iterate across the certificates in the store. |
| **CERT_FIND_CERT_ID** | Data type of *pvFindPara*: [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure.<br><br>Find the certificate identified by the specified [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id). |
| **CERT_FIND_CTL_USAGE** | Data type of *pvFindPara*: [CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure.<br><br>Searches for a certificate that has a szOID_ENHANCED_KEY_USAGE extension or a CERT_CTL_PROP_ID that matches the **pszUsageIdentifier** member of the [CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure. |
| **CERT_FIND_ENHKEY_USAGE** | Data type of *pvFindPara*: [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure.<br><br>Searches for a certificate in the store that has either an [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) extension or an enhanced key usage property and a usage identifier that matches the **cUsageIdentifier** member in the  [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure.<br><br>A certificate has an enhanced key usage extension if it has a [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure with the **pszObjId** member set to szOID_ENHANCED_KEY_USAGE.<br><br>A certificate has an enhanced key usage property if its CERT_ENHKEY_USAGE_PROP_ID identifier is set.<br><br>If CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG is set in *dwFindFlags*, certificates without the key usage extension or property are also matches. Setting this flag takes precedence over passing **NULL** in *pvFindPara*.<br><br>If CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG is set, a match is done only on the key usage extension.<br><br>For information about flag modifications to search criteria, see Remarks. |
| **CERT_FIND_EXISTING** | Data type of *pvFindPara*: [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.<br><br>Searches for a certificate that is an exact match of the specified certificate context. |
| **CERT_FIND_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a SHA1 hash that matches the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CERT_FIND_HAS_PRIVATE_KEY** | Data type of *pvFindPara*: **NULL**, not used.<br><br>Searches for a certificate that has a private key. The key can be ephemeral or saved on disk. The key can be a legacy Cryptography API (CAPI) key or a CNG key.<br><br>**Note** The order of the certificate context may not be preserved within the store. Therefore, to access a specific certificate, you must iterate across all certificates.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |
| **CERT_FIND_ISSUER_ATTR** | Data type of *pvFindPara*: [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure.<br><br>Searches for a certificate with specified issuer attributes that match attributes in the [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure. If these values are set, the function compares attributes of the issuer in a certificate with elements of the [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) array in this **CERT_RDN** structure. Comparisons iterate through the **CERT_RDN_ATTR** attributes looking for a match with the certificate's issuer attributes.<br><br>If the **pszObjId** member of [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) is **NULL**, the attribute object identifier is ignored.<br><br>If the **dwValueType** member of [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) is CERT_RDN_ANY_TYPE, the value type is ignored.<br><br>If the **pbData** member of [CERT_RDN_VALUE_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) is **NULL**, any value is a match.<br><br>Currently only an exact, case-sensitive match is supported. For information about Unicode options, see Remarks. When these values are set, the search is restricted to certificates whose encoding type matches *dwCertEncodingType*. |
| **CERT_FIND_ISSUER_NAME** | Data type of *pvFindPara*: [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Search for a certificate with an exact match of the entire issuer name with the name in [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) The search is restricted to certificates that match the *dwCertEncodingType*. |
| **CERT_FIND_ISSUER_OF** | Data type of *pvFindPara*: [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.<br><br>Searches for a certificate with a subject that matches the issuer in [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context).<br><br>Instead of using **CertFindCertificateInStore** with this value, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function. |
| **CERT_FIND_ISSUER_STR** | Data type of *pvFindPara*: Null-terminated Unicode string.<br><br>Searches for a certificate that contains the specified issuer name string. The certificate's issuer member is converted to a name string of the appropriate type using the appropriate form of [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra) formatted as CERT_SIMPLE_NAME_STR. Then a case-insensitive substring-within-a-string match is performed. When this value is set, the search is restricted to certificates whose encoding type matches *dwCertEncodingType*.<br><br>If the substring match fails and the subject contains an email RDN with Punycode encoded string, **CERT_NAME_STR_ENABLE_PUNYCODE_FLAG** is used to convert the subject to a Unicode string and the substring match is performed again. |
| **CERT_FIND_KEY_IDENTIFIER** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a CERT_KEY_IDENTIFIER_PROP_ID property that matches the key identifier in [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)). |
| **CERT_FIND_KEY_SPEC** | Data type of *pvFindPara*: **DWORD** variable that contains a key specification.<br><br>Searches for a certificate that has a CERT_KEY_SPEC_PROP_ID property that matches the key specification in *pvFindPara*. |
| **CERT_FIND_MD5_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with an MD5 hash that matches the hash in [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)). |
| **CERT_FIND_PROPERTY** | Data type of *pvFindPara*: **DWORD** variable that contains a property identifier.<br><br>Searches for a certificate with a property that matches the property identifier specified by the **DWORD** value in *pvFindPara*. |
| **CERT_FIND_PUBLIC_KEY** | Data type of *pvFindPara*: [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure.<br><br>Searches for a certificate with a public key that matches the public key in the [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure. |
| **CERT_FIND_SHA1_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a SHA1 hash that matches the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CERT_FIND_SHA1_SHA256_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a SHA1 + SHA256 hash that matches the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CERT_FIND_SHA256_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a SHA256 hash that matches the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CERT_FIND_SIGNATURE_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with a signature hash that matches the signature hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CERT_FIND_SUBJECT_ATTR** | Data type of *pvFindPara*: [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure.<br><br>Searches for a certificate with specified subject attributes that match attributes in the [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure. If RDN values are set, the function compares attributes of the subject in a certificate with elements of the [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) array in this **CERT_RDN** structure. Comparisons iterate through the **CERT_RDN_ATTR** attributes looking for a match with the certificate's subject's attributes.<br><br>If the **pszObjId** member of [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) is **NULL**, the attribute object identifier is ignored.<br><br>If the **dwValueType** member of [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) is CERT_RDN_ANY_TYPE, the value type is ignored.<br><br>If the **pbData** member of [CERT_RDN_VALUE_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) is **NULL**, any value is a match.<br><br>Currently only an exact, case-sensitive match is supported.<br><br>For information about Unicode options, see Remarks. When these values are set, the search is restricted to certificates whose encoding type matches *dwCertEncodingType*. |
| **CERT_FIND_SUBJECT_CERT** | Data type of *pvFindPara*: [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure.<br><br>Searches for a certificate with both an issuer and a serial number that match the issuer and serial number in the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure. |
| **CERT_FIND_SUBJECT_NAME** | Data type of *pvFindPara*: [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Searches for a certificate with an exact match of the entire subject name with the name in the [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. The search is restricted to certificates that match the value of *dwCertEncodingType*. |
| **CERT_FIND_SUBJECT_STR** | Data type of *pvFindPara*: Null-terminated Unicode string.<br><br>Searches for a certificate that contains the specified subject name string. The certificate's subject member is converted to a name string of the appropriate type using the appropriate form of [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra) formatted as CERT_SIMPLE_NAME_STR. Then a case-insensitive substring-within-a-string match is performed. When this value is set, the search is restricted to certificates whose encoding type matches *dwCertEncodingType*. |
| **CERT_FIND_CROSS_CERT_DIST_POINTS** | Data type of *pvFindPara*: Not used.<br><br>Find a certificate that has either a cross certificate distribution point extension or property. |
| **CERT_FIND_PUBKEY_MD5_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure.<br><br>Find a certificate whose MD5-hashed public key matches the specified hash. |

**Note** There are alternate forms of the value of *dwFindType* that pass a string in *pvFindPara*. One form uses a Unicode string, and the other an [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string. Values that end in "_W" or without a suffix use Unicode. Values that end with "_A" use ASCII strings.

### `pvFindPara` [in]

Points to a data item or structure used with *dwFindType*.

### `pPrevCertContext` [in]

A pointer to the last
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure returned by this function. This parameter must be **NULL** on the first call of the function. To find successive certificates meeting the search criteria, set *pPrevCertContext* to the pointer returned by the previous call to the function. This function frees the **CERT_CONTEXT** referenced by non-**NULL** values of this parameter.

## Return value

If the function succeeds, the function returns a pointer to a read-only [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.

If the function fails and a certificate that matches the search criteria is not found, the return value is **NULL**.

A non-**NULL** [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) that **CertFindCertificateInStore** returns must be freed by
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) or by being passed as the *pPrevCertContext* parameter on a subsequent call to **CertFindCertificateInStore**.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | No certificate was found matching the search criteria. This can happen if the store is empty or the end of the store's list is reached. |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) pointed to by the *pPrevCertContext* parameter, or a value that is not valid was specified in the *dwFindType* parameter. |

## Remarks

The *dwFindFlags* parameter is used to modify the criteria of some search types.

The CERT_UNICODE_IS_RDN_ATTRS_FLAG *dwFindFlags* value is used only with the CERT_FIND_SUBJECT_ATTR and CERT_FIND_ISSUER_ATTR values for *dwFindType*. CERT_UNICODE_IS_RDN_ATTRS_FLAG must be set if the [CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structure pointed to by *pvFindPara* was initialized with Unicode strings. Before any comparison is made, the string to be matched is converted by using X509_UNICODE_NAME to provide for Unicode comparisons.

The following *dwFindFlags* values are used only with the CERT_FIND_ENKEY_USAGE value for *dwFindType*:

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) can be called to make a duplicate of the returned context. The returned context can be added to a different [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) by using
[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore), or a link to that certificate context can be added to a store that is not a collection store by using
[CertAddCertificateLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatelinktostore).

The returned pointer is freed when passed as the *pPrevCertContext* parameter on a subsequent call to the function. Otherwise, the pointer must be explicitly freed by calling
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext). A *pPrevCertContext* that is not **NULL** is always freed by **CertFindCertificateInStore** using a call to **CertFreeCertificateContext**, even if there is an error in the function.

#### Examples

The following example shows finding a certificate context in the certificate store meeting a search criterion. For a complete example that includes the context for this example, see
[Example C Program: Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-certificate-store-operations).

For another example that uses this function, see [Example C Program: Collection and Sibling Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-collection-and-sibling-certificate-store-operations).

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>
#pragma comment(lib, "crypt32.lib")

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)

void main()
{
//-------------------------------------------------------------------
// Declare and initialize variables.
HCERTSTORE  hSystemStore;              // The system store handle.
PCCERT_CONTEXT  pDesiredCert = NULL;   // Set to NULL for the first
                                       // call to
                                       // CertFindCertificateInStore.
LPCSTR lpszCertSubject = (LPCSTR) "Cert_subject_1";

//-------------------------------------------------------------------
// Open the certificate store to be searched.

if(hSystemStore = CertOpenStore(
     CERT_STORE_PROV_SYSTEM,
     0,                      // Encoding type not needed
                             // with this PROV.
     NULL,                   // Accept the default HCRYPTPROV.
     CERT_SYSTEM_STORE_CURRENT_USER,
                             // Set the system store location in
                             // the registry.
     L"MY"))                 // Could have used other predefined
                             // system stores
                             // including Trust, CA, or Root.
{
   printf("Opened the MY system store. \n");
}
else
{
   printf( "Could not open the MY system store.\n");
   exit(1);
}
//-------------------------------------------------------------------
// Get a certificate that has lpszCertSubject as its
// subject.

if(pDesiredCert=CertFindCertificateInStore(
      hSystemStore,
      MY_ENCODING_TYPE,           // Use X509_ASN_ENCODING.
      0,                          // No dwFlags needed.
      CERT_FIND_SUBJECT_STR,      // Find a certificate with a
                                  // subject that matches the string
                                  // in the next parameter.
      lpszCertSubject ,           // The Unicode string to be found
                                  // in a certificate's subject.
      NULL))                      // NULL for the first call to the
                                  // function. In all subsequent
                                  // calls, it is the last pointer
                                  // returned by the function.
{
  printf("The desired certificate was found. \n");
}
else
{
   printf("Could not find the desired certificate.\n");
}
//-------------------------------------------------------------------
// Clean up.

if(pDesiredCert)
    CertFreeCertificateContext(pDesiredCert);
if(hSystemStore)
    CertCloseStore(
        hSystemStore,
        CERT_CLOSE_STORE_CHECK_FLAG);

```

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore)

[CertAddCertificateLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatelinktostore)

[CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext)

[CertEnumCertificatesInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumcertificatesinstore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)

[CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)