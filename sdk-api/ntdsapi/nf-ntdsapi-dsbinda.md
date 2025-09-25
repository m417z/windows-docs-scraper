# DsBindA function

## Description

The **DsBind** function binds to a domain controller.**DsBind** uses the default process credentials to bind to the domain controller. To specify alternate credentials, use the
[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

## Parameters

### `DomainControllerName` [in, optional]

Pointer to a null-terminated string that contains the name of the domain controller to bind to. This name can be the name of the domain controller or the fully qualified DNS name of the domain controller. Either name type can, optionally, be preceded by two backslash characters. All of the following examples represent correctly formatted domain controller names:

* "FAB-DC-01"
* "\\FAB-DC-01"
* "FAB-DC-01.fabrikam.com"
* "\\FAB-DC-01.fabrikam.com"

This parameter can be **NULL**. For more information, see Remarks.

### `DnsDomainName` [in, optional]

Pointer to a null-terminated string that contains the fully qualified DNS name of the domain to bind to. This parameter can be **NULL**. For more information, see Remarks.

### `phDS` [out]

Address of a **HANDLE** value that receives the binding handle. To close this handle, pass it to the [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) function.

## Return value

Returns **ERROR_SUCCESS** if successful or a Windows or RPC error code otherwise. The following are the most common error codes.

## Remarks

The behavior of the
**DsBind** function is determined by the contents of the *DomainControllerName* and *DnsDomainName* parameters. The following list describes the behavior of this function based on the contents of these parameters.

| *DomainControllerName* | *DnsDomainName* | Description |
| --- | --- | --- |
| **NULL** | **NULL** | **DsBind** will attempt to bind to a global catalog server in the forest of the local computer. |
| (value) | **NULL** | **DsBind** will attempt to bind to the domain controller specified by the *DomainControllerName* parameter. |
| **NULL** | (value) | **DsBind** will attempt to bind to any domain controller in the domain specified by *DnsDomainName* parameter. |
| (value) | (value) | The *DomainControllerName* parameter takes precedence. **DsBind** will attempt to bind to the domain controller specified by the *DomainControllerName* parameter. |

> [!NOTE]
> The ntdsapi.h header defines DsBind as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DOMAIN_CONTROLLER_INFO](https://learn.microsoft.com/windows/desktop/api/dsgetdc/ns-dsgetdc-domain_controller_infoa)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)