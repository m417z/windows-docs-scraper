# DsEnumerateDomainTrustsW function

## Description

The **DsEnumerateDomainTrusts** function obtains domain trust data for a specified domain.

## Parameters

### `ServerName` [in, optional]

Pointer to a null-terminated string that specifies the name of a computer in the domain to obtain the trust information for. If this parameter is **NULL**, the name of the local computer is used. The caller must be an authenticated user in this domain.

If this computer is a domain controller, this function returns the trust data immediately. If this computer is not a domain controller, this function obtains the trust data from cached data if the cached data is not expired. If the cached data is expired, this function obtains the trust data from a domain controller in the domain that this computer is a member of and updates the cache. The cached data automatically expires after five minutes.

### `Flags` [in]

Contains a set of flags that determines which domain trusts to enumerate. This can be zero or a combination of one or more of the following values.

#### DS_DOMAIN_DIRECT_INBOUND

Enumerate domains that directly trust the domain which has *ServerName* as a member.

#### DS_DOMAIN_DIRECT_OUTBOUND

Enumerate domains directly trusted by the domain which has *ServerName* as a member.

#### DS_DOMAIN_IN_FOREST

Enumerate domains that are a member of the same forest which has *ServerName* as a member.

#### DS_DOMAIN_NATIVE_MODE

Enumerate domains where the primary domain is running in Windows 2000 native mode.

#### DS_DOMAIN_PRIMARY

Enumerate domains that are the primary domain of the domain which has *ServerName* as a member.

#### DS_DOMAIN_TREE_ROOT

Enumerate domains that are at the root of the forest which has *ServerName* as a member.

### `Domains` [out]

Pointer to a **PDS_DOMAIN_TRUSTS** value that receives an array of [DS_DOMAIN_TRUSTS](https://learn.microsoft.com/windows/desktop/api/dsgetdc/ns-dsgetdc-ds_domain_trustsa) structures. Each structure in this array contains trust data about a domain. The caller must free this memory when it is no longer required by calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

### `DomainCount` [out]

Pointer to a **ULONG** value that receives the number of elements returned in the *Domains* array.

##### - Flags.DS_DOMAIN_DIRECT_INBOUND

Enumerate domains that directly trust the domain which has *ServerName* as a member.

##### - Flags.DS_DOMAIN_DIRECT_OUTBOUND

Enumerate domains directly trusted by the domain which has *ServerName* as a member.

##### - Flags.DS_DOMAIN_IN_FOREST

Enumerate domains that are a member of the same forest which has *ServerName* as a member.

##### - Flags.DS_DOMAIN_NATIVE_MODE

Enumerate domains where the primary domain is running in Windows 2000 native mode.

##### - Flags.DS_DOMAIN_PRIMARY

Enumerate domains that are the primary domain of the domain which has *ServerName* as a member.

##### - Flags.DS_DOMAIN_TREE_ROOT

Enumerate domains that are at the root of the forest which has *ServerName* as a member.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error code otherwise. Possible error codes include those listed in the following list.

## See also

[DS_DOMAIN_TRUSTS](https://learn.microsoft.com/windows/desktop/api/dsgetdc/ns-dsgetdc-ds_domain_trustsa)

[Directory Service
Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DsEnumerateDomainTrusts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).