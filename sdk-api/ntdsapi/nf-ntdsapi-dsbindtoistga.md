# DsBindToISTGA function

## Description

The **DsBindToISTG** function binds to the computer that holds the Inter-Site Topology Generator (ISTG) role in the domain of the local computer.

## Parameters

### `SiteName` [in, optional]

Pointer to a null-terminated string that contains the site name used when binding. If this parameter is **NULL**, the site of the nearest domain controller is used.

### `phDS` [out]

Address of a **HANDLE** value that receives the bind handle. To close this handle, call [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda).

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error code otherwise.
The following are possible error codes.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsBindToISTG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).