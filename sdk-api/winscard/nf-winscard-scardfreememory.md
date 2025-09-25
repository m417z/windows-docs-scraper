# SCardFreeMemory function

## Description

The **SCardFreeMemory** function releases memory that has been returned from the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) using the SCARD_AUTOALLOCATE length designator.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) returned from [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext), or **NULL** if the creating function also specified **NULL** for its *hContext* parameter. For more information, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

### `pvMem` [in]

Memory block to be released.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardGetProviderId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetproviderida)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)

[SCardListInterfaces](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistinterfacesa)

[SCardListReaderGroups](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadergroupsa)

[SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa)