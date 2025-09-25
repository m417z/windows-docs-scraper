# DsRemoveDsServerA function

## Description

The **DsRemoveDsServer** function removes all traces of a directory service agent (DSA) from the global area of the directory service.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `ServerDN` [in]

Pointer to a null-terminated string that specifies the fully qualified distinguished name of the domain controller to remove.

### `DomainDN` [in, optional]

Pointer to a null-terminated string that specifies a domain hosted by *ServerDN*. If this parameter is **NULL**, no verification is performed to ensure that *ServerDN* is the last domain controller in *DomainDN*.

### `fLastDcInDomain` [out, optional]

Pointer to a Boolean value that receives **TRUE** if *ServerDN* is the last DC in *DomainDN* or **FALSE** otherwise. This parameter receives **FALSE** if *DomainDN* is **NULL**.

### `fCommit` [in]

Contains a Boolean value that specifies if the domain controller should actually be removed. If this parameter is nonzero, *ServerDN* is removed. If this parameter is zero, the existence of *ServerDN* is checked and *fLastDcInDomain* is written, but the domain controller is not removed.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error code if unsuccessful. Possible error codes include the following.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsRemoveDsDomain](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsremovedsdomaina)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsRemoveDsServer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).