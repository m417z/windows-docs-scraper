# DsListServersInSiteA function

## Description

The **DsListServersInSite** function lists all the servers in a site.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `site` [in]

Pointer to a null-terminated string that specifies the site name. The site name uses a distinguished name format. It is taken from the list of sites returned by the [DsListSites](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dslistsitesa) function.

### `ppServers` [out]

Pointer to a pointer to a
[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure that receives the list of servers in the site. The returned structure must be freed using
the [DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta) function.

## Return value

If the function returns a list of servers, the return value is **NO_ERROR**. If the function fails, the return value can be one of the following error codes.

## Remarks

Individual name conversion errors are reported in the returned [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure.

> [!NOTE]
> The ntdsapi.h header defines DsListServersInSite as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta)