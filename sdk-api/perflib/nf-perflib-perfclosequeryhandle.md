# PerfCloseQueryHandle function

## Description

Closes a query handle that you opened by calling [PerfOpenQueryHandle](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfopenqueryhandle).

## Parameters

### `hQuery` [in]

A handle to the query that you want to close

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[PerfOpenQueryHandle](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfopenqueryhandle)