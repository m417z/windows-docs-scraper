# DdeKeepStringHandle function

## Description

Increments the usage count associated with the specified handle. This function enables an application to save a string handle passed to the application's Dynamic Data Exchange (DDE) callback function. Otherwise, a string handle passed to the callback function is deleted when the callback function returns. This function should also be used to keep a copy of a string handle referenced by the [CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo) structure returned by the [DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo) function.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hsz` [in]

Type: **HSZ**

A handle to the string handle to be saved.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[CONVINFO](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convinfo)

**Conceptual**

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeFreeStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreestringhandle)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo)

[DdeQueryString](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerystringa)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**