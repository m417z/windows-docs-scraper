# TxfLogDestroyReadContext function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Closes a read context created by the
[TxfLogCreateFileReadContext](https://learn.microsoft.com/windows/desktop/api/txfw32/nf-txfw32-txflogcreatefilereadcontext) function.

## Parameters

### `TxfLogContext` [in]

A pointer to the context.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[TxfLogCreateFileReadContext](https://learn.microsoft.com/windows/desktop/api/txfw32/nf-txfw32-txflogcreatefilereadcontext)