# DdeUninitialize function

## Description

Frees all Dynamic Data Exchange Management Library (DDEML) resources associated with the calling application.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

**DdeUninitialize** terminates any conversations currently open for the application.

## See also

**Conceptual**

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[DdeDisconnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnectlist)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**