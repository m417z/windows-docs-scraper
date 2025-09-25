# DsGetDomainControllerInfoA function

## Description

The **DsGetDomainControllerInfo** function retrieves data about the domain controllers in a domain.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `DomainName` [in]

Pointer to a null-terminated string that specifies the domain name.

### `InfoLevel` [in]

Contains a value that indicates the version of the **DS_DOMAIN_CONTROLLER_INFO** structure to return. This can be one of the following values.

#### 1

The function provides the domain data in the [DS_DOMAIN_CONTROLLER_INFO_1](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_1a) structure format.

#### 2

The function provides the domain data in the [DS_DOMAIN_CONTROLLER_INFO_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_2a) structure format.

#### 3

The function provides the domain data in the [DS_DOMAIN_CONTROLLER_INFO_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_3a) structure format.

### `pcOut` [out]

Pointer to a **DWORD** variable that receives the number of items returned in *ppInfo* array.

### `ppInfo` [out]

Pointer to a pointer variable that receives an array of **DS_DOMAIN_CONTROLLER_INFO_*** structures. The type of structures in this array is defined by the *InfoLevel* parameter. The caller must free this array, when it is no longer required, by using
the [DsFreeDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreedomaincontrollerinfoa) function.

## Return value

If the function returns domain controller data, the return value is **ERROR_SUCCESS**. If the caller does not have the privileges to access the server objects, the return value is **ERROR_SUCCESS**, but the **DS_DOMAIN_CONTROLLER_INFO** structures could be empty.

If the function fails, the return value can be one of the following error codes.

## See also

[DS_DOMAIN_CONTROLLER_INFO_1](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_1a)

[DS_DOMAIN_CONTROLLER_INFO_2](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_2a)

[DS_DOMAIN_CONTROLLER_INFO_3](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_domain_controller_info_3a)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsFreeDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreedomaincontrollerinfoa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsGetDomainControllerInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).