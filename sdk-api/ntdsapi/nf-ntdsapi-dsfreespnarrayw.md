# DsFreeSpnArrayW function

## Description

The **DsFreeSpnArray** function frees an array returned from the
[DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna) function.

## Parameters

### `cSpn` [in]

Specifies the number of elements contained in *rpszSpn*.

### `rpszSpn` [in]

Pointer to an array returned from [DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsFreeSpnArray as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).