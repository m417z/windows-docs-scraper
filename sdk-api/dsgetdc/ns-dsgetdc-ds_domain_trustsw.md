# DS_DOMAIN_TRUSTSW structure

## Description

The **DS_DOMAIN_TRUSTS** structure is used with the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function to contain trust data for a domain.

## Members

### `NetbiosDomainName.string`

### `DnsDomainName.string`

### `NetbiosDomainName`

Pointer to a null-terminated string that contains the NetBIOS name of the domain.

### `DnsDomainName`

Pointer to a null-terminated string that contains the DNS name of the domain. This member may be **NULL**.

### `Flags`

Contains a set of flags that specify more data about the domain trust. This can be zero or a combination of one or more of the following values.

#### DS_DOMAIN_IN_FOREST (1 (0x1))

The domain represented by this structure is a member of the same forest as the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

#### DS_DOMAIN_DIRECT_OUTBOUND (2 (0x2))

The domain represented by this structure is directly trusted by the domain that the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function is a member of.

#### DS_DOMAIN_TREE_ROOT (4 (0x4))

The domain represented by this structure is the root of a tree and a member of the same forest as the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

#### DS_DOMAIN_PRIMARY (8 (0x8))

The domain represented by this structure is the primary domain of the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

#### DS_DOMAIN_NATIVE_MODE (16 (0x10))

The domain represented by this structure is running in the Windows 2000 native mode.

#### DS_DOMAIN_DIRECT_INBOUND (32 (0x20))

The domain represented by this structure directly trusts the domain that the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function is a member of.

### `ParentIndex`

Contains the index in the *Domains* array returned by the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function that corresponds to the parent domain of the domain represented by this structure. This member is only valid if the all of the following conditions are met:

* The **DS_DOMAIN_IN_FOREST** flag was specified in the *Flags* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.
* The **Flags** member of this structure does not contain the **DS_DOMAIN_TREE_ROOT** flag.

### `TrustType`

Contains a value that indicates the type of trust represented by this structure. Possible values for this member are documented in the **TrustType** member of the [TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure.

### `TrustAttributes`

Contains a value that indicates the attributes of the trust represented by this structure. Possible values for this member are documented in the **TrustAttribute** member of the [TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex) structure.

### `DomainSid`

Contains the security identifier of the domain represented by this structure.

### `DomainGuid`

Contains the GUID of the domain represented by this structure.

##### - Flags.DS_DOMAIN_DIRECT_INBOUND (32 (0x20))

The domain represented by this structure directly trusts the domain that the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function is a member of.

##### - Flags.DS_DOMAIN_DIRECT_OUTBOUND (2 (0x2))

The domain represented by this structure is directly trusted by the domain that the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function is a member of.

##### - Flags.DS_DOMAIN_IN_FOREST (1 (0x1))

The domain represented by this structure is a member of the same forest as the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

##### - Flags.DS_DOMAIN_NATIVE_MODE (16 (0x10))

The domain represented by this structure is running in the Windows 2000 native mode.

##### - Flags.DS_DOMAIN_PRIMARY (8 (0x8))

The domain represented by this structure is the primary domain of the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

##### - Flags.DS_DOMAIN_TREE_ROOT (4 (0x4))

The domain represented by this structure is the root of a tree and a member of the same forest as the server specified in the *ServerName* parameter of the [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa) function.

## See also

[Directory Service Structures](https://learn.microsoft.com/windows/desktop/AD/directory-service-structures)

[DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa)

[TRUSTED_DOMAIN_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-trusted_domain_information_ex)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DS_DOMAIN_TRUSTS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).