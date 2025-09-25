# CertFindSubjectInSortedCTL function

## Description

The **CertFindSubjectInSortedCTL** function attempts to find the specified subject in a sorted [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL). A subject can be identified either by the certificate's whole context or by any unique identifier of the certificate's subject, such as the SHA1 [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the certificate's issuer and serial number.

## Parameters

### `pSubjectIdentifier` [in]

A pointer to a
[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure uniquely identifying the subject. The information in this structure can be a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) or any unique byte sequence.

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be searched.

### `dwFlags` [in]

Reserved for future use and must be **NULL**.

### `pvReserved` [in]

Reserved for future use and must be **NULL**.

### `pEncodedAttributes` [out]

A pointer to a [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure containing a byte count and a pointer to the subject's encoded attributes.

## Return value

If the function succeeds and the subject identifier exists in the CTL, the return value is **TRUE**.

If the function fails and does not locate a matching subject identifier, the return value is **FALSE**.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertEnumSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsubjectinsortedctl)

[Certificate and Certificate Store Maintenance Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)