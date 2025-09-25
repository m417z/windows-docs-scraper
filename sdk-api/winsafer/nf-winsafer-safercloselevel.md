# SaferCloseLevel function

## Description

The **SaferCloseLevel** function closes a SAFER_LEVEL_HANDLE that was opened by using the
[SaferIdentifyLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-saferidentifylevel) function or
the [SaferCreateLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-safercreatelevel) function.

## Parameters

### `hLevelHandle` [in]

The SAFER_LEVEL_HANDLE to be closed.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).