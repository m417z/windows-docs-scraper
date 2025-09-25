## Description

The **TmRenameTransactionManager** routine changes the identity of the transaction manager object that is stored in the [CLFS](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-clfs-library) log file stream contained in the log file name.

> [!WARNING]
> Changing the identity of the transaction manger object might break any cross-log transactional links that may exist.

## Parameters

### `LogFileName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path and file name of a [CLFS](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-clfs-library) log file stream to be associated with the transaction manager object.

### `ExistingTransactionManagerGuid` [in]

A pointer to a GUID structure that represents the current name of the transaction manager object.

## Return value

The **TmRenameTransactionManager** routine returns an NTSTATUS value. If the routine fails, it returns an error code.