# DdeFreeStringHandle function

## Description

Frees a string handle in the calling application.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hsz` [in]

Type: **HSZ**

A handle to the string handle to be freed. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application can free string handles it creates with [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) but should not free those that the system passed to the application's Dynamic Data Exchange (DDE) callback function or those returned in the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure by the [DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo) function.

## See also

[CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo)

**Conceptual**

[DdeCmpStringHandles](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecmpstringhandles)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdeKeepStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddekeepstringhandle)

[DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo)

[DdeQueryString](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerystringa)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**