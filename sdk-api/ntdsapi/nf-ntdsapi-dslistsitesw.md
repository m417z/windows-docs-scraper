# DsListSitesW function

## Description

The **DsListSites** function lists all the sites in the enterprise forest.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `ppSites` [out]

Pointer to a pointer to a [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure that receives the list of sites in the enterprise. The site name is returned in the distinguished name (DN) format. The returned structure must be freed using the
[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta) function.

## Return value

If the function returns a list of sites, the return value is **NO_ERROR**. If the function fails, the return value can be one of the following error codes.

## Remarks

Individual name conversion errors are reported in the returned [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure.

> [!NOTE]
> The ntdsapi.h header defines DsListSites as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta)