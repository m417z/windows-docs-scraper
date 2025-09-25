# DsGetDcOpenW function

## Description

The **DsGetDcOpen** function opens a new domain controller enumeration operation.

## Parameters

### `DnsName` [in]

Pointer to a null-terminated string that contains the domain naming system (DNS) name of the domain to enumerate the domain controllers for. This parameter cannot be **NULL**.

### `OptionFlags` [in]

Contains a set of flags that modify the behavior of the function. This can be zero or a combination of one or more of the following values.

#### DS_ONLY_DO_SITE_NAME

Only site-specific domain controllers are enumerated.

#### DS_NOTIFY_AFTER_SITE_RECORDS

The [DsGetDcNext](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnexta) function will return the **ERROR_FILEMARK_DETECTED** value after all of the site-specific domain controllers are retrieved. **DsGetDcNext** will then enumerate the second group, which contains all domain controllers in the domain, including the site-specific domain controllers contained in the first group.

### `SiteName` [in, optional]

Pointer to a null-terminated string that contains the name of site the client is in. This parameter is optional and may be **NULL**.

### `DomainGuid` [in, optional]

Pointer to a **GUID** value that contains the identifier of the domain specified by *DnsName*.
This identifier is used to handle the case of a renamed domain. If this
value is specified and the domain specified in *DnsName* is renamed, this function attempts to enumerate domain controllers in the domain that contains the specified identifier. This parameter is optional and may be **NULL**.

### `DnsForestName` [in, optional]

Pointer to a null-terminated string that contains the name of the forest that contains the *DnsName* domain. This value is used in conjunction with *DomainGuid* to enumerate the domain controllers if the domain has been renamed. This parameter is optional and may be **NULL**.

### `DcFlags` [in]

Contains a set of flags that identify the type of domain controllers to enumerate. This can be zero or a combination of one or more of the following values.

#### DS_FORCE_REDISCOVERY

Forces cached domain controller data to be ignored. When this flag is not specified, **DsGetDcOpen** obtains the domain controller enumeration from cached domain controller data.

#### DS_GC_SERVER_REQUIRED

Requires that the enumerated domain controllers be global catalog servers for the forest of domains with this domain as the root. This flag cannot be combined with the **DS_PDC_REQUIRED** flag.

#### DS_KDC_REQUIRED

Requires that the enumerated domain controllers currently be running the Kerberos Key Distribution Center service. This flag cannot be combined with the **DS_PDC_REQUIRED** or **DS_GC_SERVER_REQUIRED** flags.

#### DS_ONLY_LDAP_NEEDED

Specifies that the enumerated servers are LDAP servers. The servers are not necessarily domain controllers. No other services are implied to be present at each enumerated server. The servers do not necessarily have a writable **config** container nor a writable **schema** container. The servers may not necessarily be used to create or modify security principles. This flag may be used with the **DS_GC_SERVER_REQUIRED** flag to enumerate LDAP servers that also host a global catalog server. In that case, the enumerated global catalog servers are not necessarily domain controllers and other services are implied to be present at each server. If this flag is specified, the **DS_PDC_REQUIRED**, **DS_TIMESERV_REQUIRED**, **DS_GOOD_TIMESERV_PREFERRED**, **DS_DIRECTORY_SERVICES_PREFERED**, **DS_DIRECTORY_SERVICES_REQUIRED**, and **DS_KDC_REQUIRED** flags are ignored.

#### DS_PDC_REQUIRED

Requires that the enumerated domain controllers be the primary domain controllers for the domain. This flag cannot be combined with the **DS_GC_SERVER_REQUIRED** flag.

### `RetGetDcContext` [out]

Pointer to a **HANDLE** value that receives the domain controller enumeration context handle. This handle is used with the [DsGetDcNext](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnexta) function to identify the domain controller enumeration operation. This handle is passed to [DsGetDcClose](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcclosew) to close the domain controller enumeration operation.

##### - DcFlags.DS_FORCE_REDISCOVERY

Forces cached domain controller data to be ignored. When this flag is not specified, **DsGetDcOpen** obtains the domain controller enumeration from cached domain controller data.

##### - DcFlags.DS_GC_SERVER_REQUIRED

Requires that the enumerated domain controllers be global catalog servers for the forest of domains with this domain as the root. This flag cannot be combined with the **DS_PDC_REQUIRED** flag.

##### - DcFlags.DS_KDC_REQUIRED

Requires that the enumerated domain controllers currently be running the Kerberos Key Distribution Center service. This flag cannot be combined with the **DS_PDC_REQUIRED** or **DS_GC_SERVER_REQUIRED** flags.

##### - DcFlags.DS_ONLY_LDAP_NEEDED

Specifies that the enumerated servers are LDAP servers. The servers are not necessarily domain controllers. No other services are implied to be present at each enumerated server. The servers do not necessarily have a writable **config** container nor a writable **schema** container. The servers may not necessarily be used to create or modify security principles. This flag may be used with the **DS_GC_SERVER_REQUIRED** flag to enumerate LDAP servers that also host a global catalog server. In that case, the enumerated global catalog servers are not necessarily domain controllers and other services are implied to be present at each server. If this flag is specified, the **DS_PDC_REQUIRED**, **DS_TIMESERV_REQUIRED**, **DS_GOOD_TIMESERV_PREFERRED**, **DS_DIRECTORY_SERVICES_PREFERED**, **DS_DIRECTORY_SERVICES_REQUIRED**, and **DS_KDC_REQUIRED** flags are ignored.

##### - DcFlags.DS_PDC_REQUIRED

Requires that the enumerated domain controllers be the primary domain controllers for the domain. This flag cannot be combined with the **DS_GC_SERVER_REQUIRED** flag.

##### - OptionFlags.DS_NOTIFY_AFTER_SITE_RECORDS

The [DsGetDcNext](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnexta) function will return the **ERROR_FILEMARK_DETECTED** value after all of the site-specific domain controllers are retrieved. **DsGetDcNext** will then enumerate the second group, which contains all domain controllers in the domain, including the site-specific domain controllers contained in the first group.

##### - OptionFlags.DS_ONLY_DO_SITE_NAME

Only site-specific domain controllers are enumerated.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error otherwise. Possible error values include the following.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetDcClose](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcclosew)

[DsGetDcNext](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnexta)

[Enumerating Domain Controllers](https://learn.microsoft.com/windows/desktop/AD/enumerating-domain-controllers)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DsGetDcOpen as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).