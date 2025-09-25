# DsQuerySitesFree function

## Description

The **DsQuerySitesFree** function frees the memory allocated by the [DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta) function.

## Parameters

### `rgSiteInfo` [in]

Pointer to an array of [DS_SITE_COST_INFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_site_cost_info) structures allocated by a call to [DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta).

## See also

[DS_SITE_COST_INFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_site_cost_info)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta)