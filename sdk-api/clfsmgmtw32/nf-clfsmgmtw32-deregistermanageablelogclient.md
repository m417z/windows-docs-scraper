# DeregisterManageableLogClient function

## Description

The **DeregisterManageableLogClient** function deregisters a client with the log manager.

## Parameters

### `hLog` [in]

The handle to deregister.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[RegisterManageableLogClient](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-registermanageablelogclient)