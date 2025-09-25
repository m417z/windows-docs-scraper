# DOMAIN_CONTROLLER_INFOA structure

## Description

The **DOMAIN_CONTROLLER_INFO** structure is used with the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function to receive data about a domain controller.

## Members

### `DomainControllerName`

Pointer to a null-terminated string that specifies the computer name of the discovered domain controller. The returned computer name is prefixed with "\\". The DNS-style name, for example, "\\phoenix.fabrikam.com", is returned, if available. If the DNS-style name is not available, the flat-style name (for example, "\\phoenix") is returned. This example would apply if the domain is a Windows NT 4.0 domain or if the domain does not support the IP family of protocols.

### `DomainControllerAddress`

Pointer to a null-terminated string that specifies the address of the discovered domain controller. The address is prefixed with "\\". This string is one of the types defined by the **DomainControllerAddressType** member.

### `DomainControllerAddressType`

Indicates the type of string that is contained in the **DomainControllerAddress** member. This can be one of the following values.

#### DS_INET_ADDRESS

The address is a string IP address (for example, "\\157.55.94.74") of the domain controller.

#### DS_NETBIOS_ADDRESS

The address is a NetBIOS name, for example, "\\phoenix", of the domain controller.

### `DomainGuid`

The **GUID** of the domain. This member is zero if the domain controller does not have a Domain GUID; for example, the domain controller is not a Windows 2000 domain controller.

### `DomainName`

Pointer to a null-terminated string that specifies the name of the domain. The DNS-style name, for example, "fabrikam.com", is returned if available. Otherwise, the flat-style name, for example, "fabrikam", is returned. This name may be different than the requested domain name if the domain has been renamed.

### `DnsForestName`

Pointer to a null-terminated string that specifies the name of the domain at the root of the DS tree. The DNS-style name, for example, "fabrikam.com", is returned if available. Otherwise, the flat-style name, for example, "fabrikam" is returned.

### `Flags`

Contains a set of flags that describe the domain controller.
This can be zero or a combination of one or more of the following values.

#### DS_DNS_CONTROLLER_FLAG

The **DomainControllerName** member is in DNS format.

#### DS_DNS_DOMAIN_FLAG

The **DomainName** member is in DNS format.

#### DS_DNS_FOREST_FLAG

The **DnsForestName** member is in DNS format.

#### DS_CLOSEST_FLAG

The domain controller is in the same site as the client.

#### DS_DS_FLAG

The domain controller is a directory service server for the domain.

#### DS_FULL_SECRET_DOMAIN_6_FLAG

The domain controller is a Windows 2008 or later writable domain controller.

#### DS_GOOD_TIMESERV_FLAG

The domain controller is running a reliable Windows Time Service for the domain.

#### DS_GC_FLAG

The domain controller is a global catalog server for the forest specified by **DnsForestName**.

#### DS_KDC_FLAG

The domain controller is a Kerberos Key Distribution Center for the domain.

#### DS_LDAP_FLAG

The server is an LDAP server.

#### DS_NDNC_FLAG

The Domain Name is an application (non-domain) naming context.

#### DS_PDC_FLAG

The domain controller is the primary domain controller of the domain.

#### DS_SELECT_SECRET_DOMAIN_6_FLAG

The domain controller is a Windows 2008 or later read-only domain controller.

#### DS_TIMESERV_FLAG

The domain controller is running the Windows Time Service for the domain.

#### DS_WRITABLE_FLAG

The domain controller hosts a writable directory service (or SAM).

### `DcSiteName`

Pointer to a null-terminated string that specifies the name of the site where the domain controller is located. This member may be **NULL** if the domain controller is not in a site; for example, the domain controller is a Windows NT 4.0 domain controller.

### `ClientSiteName`

Pointer to a null-terminated string that specifies the name of the site that the computer belongs to. The computer is specified in the *ComputerName* parameter passed to [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea). This member may be **NULL** if the site that contains the computer cannot be found; for example, if the DS administrator has not associated the subnet that the computer is in with a valid site.

## See also

[Directory Service Structures](https://learn.microsoft.com/windows/desktop/AD/directory-service-structures)

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DOMAIN_CONTROLLER_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).