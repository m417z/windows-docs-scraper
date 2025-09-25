# DS_DOMAIN_CONTROLLER_INFO_3W structure

## Description

The **DS_DOMAIN_CONTROLLER_INFO_3** structure contains data about a domain controller. This structure is returned by the
[DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa) function.

## Members

### `string`

### `unique`

### `NetbiosName`

Pointer to a null-terminated string that specifies the NetBIOS name of the domain controller.

### `DnsHostName`

Pointer to a null-terminated string that specifies the DNS host name of the domain controller.

### `SiteName`

Pointer to a null-terminated string that specifies the site to which the domain controller belongs.

### `SiteObjectName`

Pointer to a null-terminated string that specifies the name of the site object on the domain controller.

### `ComputerObjectName`

Pointer to a null-terminated string that specifies the name of the computer object on the domain controller.

### `ServerObjectName`

Pointer to a null-terminated string that specifies the name of the server object on the domain controller.

### `NtdsDsaObjectName`

Pointer to a null-terminated string that specifies the name of the NTDS DSA object on the domain controller.

### `fIsPdc`

A Boolean value that indicates whether or not this domain controller is the primary domain controller. If this value is **TRUE**, the domain controller is the primary domain controller; otherwise, the domain controller is not the primary domain controller.

### `fDsEnabled`

A Boolean value that indicates whether or not the domain controller is enabled. If this value is **TRUE**, the domain controller is enabled; otherwise, it is not enabled.

### `fIsGc`

A Boolean value that indicates whether or not the domain controller is global catalog server. If this value is **TRUE**, the domain controller is a global catalog server; otherwise, it is not a global catalog server.

### `fIsRodc`

A Boolean value that indicates if the domain controller is a read-only domain controller. If this value is **TRUE**, the domain controller is a read-only domain controller; otherwise, it is not a read-only domain controller.

### `SiteObjectGuid`

Contains the **GUID** for the site object on the domain controller.

### `ComputerObjectGuid`

Contains the **GUID** for the computer object on the domain controller.

### `ServerObjectGuid`

Contains the **GUID** for the server object on the domain controller.

### `NtdsDsaObjectGuid`

Contains the **GUID** for the NTDS DSA object on the domain controller.

## Remarks

The [DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa) function can return different versions of this structure. For more information and a list of the currently supported versions, see the *InfoLevel* parameter of **DsGetDomainControllerInfo**.

> [!NOTE]
> The ntdsapi.h header defines DS_DOMAIN_CONTROLLER_INFO_3 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa)