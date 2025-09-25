# DsFreeNameResultW function

## Description

The **DsFreeNameResult** function frees the memory held by a
[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure. Use this function to free the memory allocated by the
[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function.

## Parameters

### `pResult`

Pointer to the [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure to be freed.

## See also

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsFreeNameResult as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).