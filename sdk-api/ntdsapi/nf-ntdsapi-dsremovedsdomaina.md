# DsRemoveDsDomainA function

## Description

The **DsRemoveDsDomain** function removes all traces of a domain naming context from the global area of the directory service.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `DomainDN` [in]

Pointer to a null-terminated string that specifies the distinguished name of the naming context to remove from the directory service.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error code if unsuccessful. Possible error codes include the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsRemoveDsServer](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsremovedsservera)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsRemoveDsDomain as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).