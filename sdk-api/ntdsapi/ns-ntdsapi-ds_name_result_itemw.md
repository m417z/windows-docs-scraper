# DS_NAME_RESULT_ITEMW structure

## Description

The **DS_NAME_RESULT_ITEM** structure contains a name converted by the
[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function, along with associated error and domain data.

## Members

### `status`

Contains one of the [DS_NAME_ERROR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_error) values that indicates the status of this name conversion.

### `string`

### `unique`

### `pDomain`

Pointer to a null-terminated string that specifies the DNS domain in which the object resides. This member will contain valid data if **status** contains [DS_NAME_NO_ERROR](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_error) or **DS_NAME_ERROR_DOMAIN_ONLY**.

### `pName`

Pointer to a null-terminated string that specifies the newly formatted object name.

## Remarks

The [DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function returns an array of **DS_NAME_RESULT_ITEM** structures as part of the [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure.

> [!NOTE]
> The ntdsapi.h header defines DS_NAME_RESULT_ITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)