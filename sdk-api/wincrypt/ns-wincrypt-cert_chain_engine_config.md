# CERT_CHAIN_ENGINE_CONFIG structure

## Description

The **CERT_CHAIN_ENGINE_CONFIG** structure sets parameters for building a non-default certificate chain engine. The engine used determines the ways that certificate chains are built.

## Members

### `cbSize`

Size of this structure in bytes.

### `hRestrictedRoot`

This configuration parameter can be used to restrict the root store. If used, it can be the handle of any HCERTSTORE containing only a proper subset of the certificates in the root store.

### `hRestrictedTrust`

Store handle. If used, restricts the stores searched to find CTLs.

### `hRestrictedOther`

Store handle. If used, restricts the [stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) searched for certificates and [CRLs](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `cAdditionalStore`

Count of additional stores to be searched for certificates and CRLs needed to build chains.

### `rghAdditionalStore`

A pointer to an array of store handles for any additional stores to be searched in building chains.

### `dwFlags`

The following flags are defined.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_CACHE_END_CERT**<br><br>0x00000001 | Information in the end certificate is cached. By default, information in all certificates except the end certificate is cached as a chain is built. Setting this flag extends the caching to the end certificate. |
| **CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL**<br><br>0x00000004 | Use only cached URLs in building a certificate chain. The Internet and intranet are not searched for URL-based objects. |
| **CERT_CHAIN_USE_LOCAL_MACHINE_STORE**<br><br>0x00000008 | Build the chain using the LocalMachine registry location as opposed to the CurrentUser location. |
| **CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE**<br><br>0x00000010 | Enable automatic updating of the cache as a chain is being built. |
| **CERT_CHAIN_ENABLE_SHARE_STORE**<br><br>0x00000020 | Allow certificate stores used to build the chain to be shared. |
| **CERT_CHAIN_DISABLE_AIA**<br><br>0x00002000 | Turn off Authority Information Access (AIA) retrievals explicitly. |

### `dwUrlRetrievalTimeout`

Number of milliseconds before a time-out for network based–URL object retrievals. Can be set to zero to use the default limit.

### `MaximumCachedCertificates`

Limit on the number of certificates that can be cached as a chain is built. Can be set to 0 to use the default limit.

### `CycleDetectionModulus`

Number of certificates added to the chain before a check is made to determine whether there is a cycle of certificates in the chain. A cycle may be defined as having the same certificate in two different places in a chain.

The lower the number, the more frequently checks will be made. Extra checking for cycles of certificates will slow the process considerably. This parameter can be set to zero to use the default limit.

### `hExclusiveRoot`

Handle to a certificate store that contains exclusive trust anchors. If either the **hExclusiveRoot** or **hExclusiveTrustedPeople** member points to a valid store, exclusive trust mode is used for the chain building.

**Windows 7 and Windows Server 2008 R2:** Support for this member begins.

### `hExclusiveTrustedPeople`

Handle to a certificate store that contains application-specific peer trusted certificates. If either the **hExclusiveRoot** or **hExclusiveTrustedPeople** member points to a valid store, exclusive trust mode is used for the chain building.

**Windows 7 and Windows Server 2008 R2:** Support for this member begins.

### `dwExclusiveFlags`

The following flag can be set. The flag applies only if the **hExclusiveRoot** or **hExclusiveTrustedPeople** or both are not **NULL**.

**Windows 8 and Windows Server 2012:** Support for this member begins.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG**<br><br>0x00000001 | Indicates that a non-self-signed intermediate CA certificate in the **hExclusiveRoot** store should be treated as a trust anchor during certificate validation. If a certificate chains up to this CA, chain building is terminated and the certificate is considered trusted. No signature verification or revocation checking is performed on the CA certificate.<br><br>By default, if this flag is not set, only self-signed certificates in the **hExclusiveRoot** store are treated as trust anchors.<br><br>See also the **CERT_TRUST_IS_CA_TRUSTED** value in the [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure. |

## Remarks

The chain-building engine uses four certificate stores in building chains. These are hRoot, hWorld, hTrust, and hOther. These stores' handles are established by using information in this structure when a chain engine is created.

hRoot is the store handle from **hRestrictedRoot** or, if **hRestrictedRoot** is **NULL**, the handle for System Store "Root."

hWorld is a collection certificate store including sibling stores hRoot, "CA," "My," "Trust," and any additional stores whose handles are in the array pointed to by **rghAdditionalStore**.

hTrust is the store handle from **hRestrictedTrust** or, if **hRestrictedTrust** is **NULL**, hWorld.

hOther is **hRestrictedOther** plus hRoot or, if **hRestrictedTrust** is non-**NULL**, the hWorld collection store plus the store handle from **hRestrictedTrust**.

Exclusive trust mode allows applications to specify trust anchors and peer-trusted certificates for certificate chain validation. In the exclusive trust mode, the root store and the trusted people store on the system are ignored, and the anchors and certificates pointed to by the **hExclusiveRoot** and **hExclusiveTrustedPeople** members are used instead.

## See also

[CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status)

[CertCreateCertificateChainEngine](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatechainengine)