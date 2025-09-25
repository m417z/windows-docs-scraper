# CERT_REVOCATION_PARA structure

## Description

The **CERT_REVOCATION_PARA** structure is passed in calls to
the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function to assist in finding the issuer of the context to be verified. The **CERT_REVOCATION_PARA** structure is an optional parameter in the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pIssuerCert`

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate of the issuer of a certificate specified in the *rgpvContext* array in the
[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) parameter list.

### `cCertStore`

When set, contains the number of elements in the **rgCertStore** array. Set to zero if you are not supplying a list of store handles in the *rgCertStore* parameter.

### `rgCertStore`

An array of [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) handles. Specifies a set of stores that are searched for issuer certificates. If *rgCertStore* is not set, the default stores are searched.

### `hCrlStore`

Optional store handle. When specified, a handler that uses [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) can search this store for CRLs.

### `pftTimeToUse`

A pointer to a **FILETIME** version of UTC time. When specified, the handler must, if possible, determine revocation status relative to the time given. If **NULL** or the handler cannot determine the status relative to the **pftTimeToUse** value, revocation status can be determined independent of time or relative to current time.

### `dwUrlRetrievalTimeout`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. The time-out, in milliseconds, that the revocation handler will wait when attempting to retrieve revocation information. If it is set to zero, the revocation handler's default time-out is used. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to zero if it is unused.

### `fCheckFreshnessTime`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. If **TRUE**, an attempt is made to retrieve a new CRL if the issue date of the CRL is less than or equal to the Current Time minus **dwFreshnessTime**. If this flag is not set, the CRL's NextUpdate time is used. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to **FALSE** if it is unused.

### `dwFreshnessTime`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. The time, in seconds, is used to determine whether an attempt will be made to retrieve a new CRL. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to zero if it is unused.

### `pftCurrentTime`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. A pointer to a **FILETIME** structure that is used in the freshness time check. If the value of this pointer is null, the revocation handler uses the current time. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to null if it is unused.

### `pCrlInfo`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. This member contains a pointer to a PCERT_REVOCATION_CRL_INFO structure that contains CRL context information. The CRL information is only applicable to the last [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) checked. To access the information in this CRL, call the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function with *cContext* set to 1. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, the member must be set to null if it is unused.

### `pftCacheResync`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. This member contains a pointer to a **FILETIME** structure that specifies the use of cached information. Any information cached before the specified time is considered invalid and new information is retrieved. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to null if it is unused.

**Windows Server 2003 and Windows XP:** This member is not used.

### `pChainPara`

This member is defined only if **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined. This member contains a pointer to a [CERT_REVOCATION_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_revocation_chain_para) structure that contains parameters used for building a chain for an independent OCSP signer certificate. If **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** is defined, this member must be set to null if it is unused.

**Windows Vista, Windows Server 2003 and Windows XP:** This member is not used in the listed systems. The member is available beginning with Windows Vista with SP1.

## Remarks

The **CERT_REVOCATION_PARA** structure provides additional information that the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function can use to determine the context issuer.

 If your application must check the freshness of the CRL or resynchronize the CRL cache, you can provide extra structure members to assist the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function with this. To include the additional structure members, define the constant **CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS** in your application before including Wincrypt.h

## See also

[CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation)