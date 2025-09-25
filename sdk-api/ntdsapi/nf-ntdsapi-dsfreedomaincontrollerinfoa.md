# DsFreeDomainControllerInfoA function

## Description

The **DsFreeDomainControllerInfo** function frees memory that is allocated by
[DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa) for data about the domain controllers in a domain.

## Parameters

### `InfoLevel` [in]

Indicates what version of the **DS_DOMAIN_CONTROLLER_INFO** structure should be freed. This parameter can be one of the following values.

#### 1

The function frees the structure that contains [DS_DOMAIN_CONTROLLER_INFO_1](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_1a) data.

#### 2

The function frees the structure that contains [DS_DOMAIN_CONTROLLER_INFO_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_2a) data.

### `cInfo` [in]

Indicates the number of items in *pInfo*.

### `pInfo` [in]

Pointer to an array of [DS_DOMAIN_CONTROLLER_INFO](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_1a) structures to be freed.

## Return value

This function does not return a value.

## See also

[DS_DOMAIN_CONTROLLER_INFO_1](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_1a)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsFreeDomainControllerInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).