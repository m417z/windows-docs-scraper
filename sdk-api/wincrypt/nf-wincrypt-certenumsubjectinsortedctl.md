# CertEnumSubjectInSortedCTL function

## Description

The **CertEnumSubjectInSortedCTL** function retrieves the first or next TrustedSubject in a sorted [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL). A sorted CTL is a CTL created with the CERT_CREATE_CONTEXT_SORTED_FLAG set. Used in a loop, this function can retrieve in sequence all TrustedSubjects in a sorted CTL.

## Parameters

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be searched.

### `ppvNextSubject` [in, out]

A pointer to the address of the last TrustedSubject found. To start the enumeration, *ppvNextSubject* must point to a pointer set to **NULL**. Upon return, the pointer addressed by *ppvNextSubject* is updated to point to the next TrustedSubject in the encoded sequence.

### `pSubjectIdentifier` [out]

A pointer to a
[CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure, uniquely identifying a TrustedSubject. The information in this structure can be a hash or any unique byte sequence.

### `pEncodedAttributes` [out]

A pointer to a [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure containing a byte count and a pointer to the TrustedSubject's encoded attributes.

## Return value

If the function succeeds, the return value is **TRUE**, with *ppvNextSubject* updated to point to the next TrustedSubject in the encoded sequence.

If the function fails, the return value is **FALSE**. The return value is **FALSE** if there are no more subjects or there is an argument that is not valid.

## Remarks

The **pbData** members of [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures point directly to the encoded bytes. The **CRYPT_DER_BLOB** structures, themselves, must be allocated and freed by the application, but the memory addressed by the **pbData** members of these structures is not allocated by the application and must not be freed by the application.

If the CTL is not sorted with the CERT_CREATE_CONTEXT_SORTED_FLAG flag set, an error results.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertFindSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinsortedctl)

[Certificate and Certificate Store Maintenance Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)