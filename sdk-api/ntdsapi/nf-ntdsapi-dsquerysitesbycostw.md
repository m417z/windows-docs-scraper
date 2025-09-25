# DsQuerySitesByCostW function

## Description

The **DsQuerySitesByCost** function gets the communication cost between one site and one or more other sites.

## Parameters

### `hDS` [in]

A directory service handle.

### `pwszFromSite` [in]

Pointer to a null-terminated string that contains the relative distinguished name of the site the costs are measured from.

### `rgwszToSites` [in]

Contains an array of null-terminated string pointers that contain the relative distinguished names of the sites the costs are measured to.

### `cToSites` [in]

Contains the number of elements in the *rgwszToSites* array.

### `dwFlags` [in]

Reserved.

### `prgSiteInfo` [out]

Pointer to an array of [DS_SITE_COST_INFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_site_cost_info) structures that receives the cost data. Each element in this array contains the cost data between the site identified by the *pwszFromSite* parameter and the site identified by the corresponding *rgwszToSites* element.

The caller must free this memory when it is no longer required by calling [DsQuerySitesFree](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesfree).

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error code otherwise.
Possible error codes include values listed in the following list.

## Remarks

The cost values obtained by this function are only used to compare and have no meaning by themselves. For example, the cost for site 1 can be compared to the cost for site 2, but the cost for site 1 cannot be compared to a fixed value.

> [!NOTE]
> The ntdsapi.h header defines DsQuerySitesByCost as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_SITE_COST_INFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_site_cost_info)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsQuerySitesFree](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesfree)