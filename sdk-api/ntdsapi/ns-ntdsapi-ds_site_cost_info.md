# DS_SITE_COST_INFO structure

## Description

The **DS_SITE_COST_INFO** structure is used with the [DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta) function to contain communication cost data.

## Members

### `errorCode`

Contains a success or error code that indicates if the cost data for the site could be obtained. This member can contain one of the following values.

#### ERROR_SUCCESS

The communication cost of the site was obtained and is contained in the **cost** member of this structure.

#### ERROR_DS_OBJ_NOT_FOUND

The communication cost of the site cannot be obtained. The **cost** member of this structure should be ignored.

### `cost`

If the **errorCode** member contains **ERROR_SUCCESS**, this member contains the communication cost value of the site. If the **errorCode** member contains **ERROR_DS_OBJ_NOT_FOUND**, this contents of this member is undefined.

## See also

[DC and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsQuerySitesByCost](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsquerysitesbycosta)