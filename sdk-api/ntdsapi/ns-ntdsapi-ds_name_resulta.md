# DS_NAME_RESULTA structure

## Description

The **DS_NAME_RESULT** structure is used with the [DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function to contain the names converted by the function.

## Members

### `cItems`

Contains the number of elements in the **rItems** array.

### `size_is`

### `size_is.cItems`

### `rItems`

Contains an array of [DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema) structure pointers. Each element of this array represents a single converted name.

## See also

[DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema)

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DS_NAME_RESULT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).