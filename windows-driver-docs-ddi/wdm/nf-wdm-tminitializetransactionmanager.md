# TmInitializeTransactionManager function

## Description

The **TmInitializeTransactionManager** routine initializes a transaction manager object.

## Parameters

### `TransactionManager` [in]

A pointer to the transaction manager object to initialize.

### `LogFileName` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path and file name of a [CLFS](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-clfs-library) log file stream associated with the transaction manager object.

### `TmId` [in]

Specifies a pointer to a GUID that identifies the name of the transaction manager object to initialize.

### `CreateOptions` [in, optional]

Optional object creation flags. The following table contains the available flags.

| Option flag | Meaning |
| --- | --- |
| TRANSACTION_MANAGER_VOLATILE | The transaction manager object will be volatile. Therefore, it will not use a log file. |
| TRANSACTION_MANAGER_COMMIT_DEFAULT | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES | For internal use only. |
| TRANSACTION_MANAGER_COMMIT_LOWEST | For internal use only. |
| TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY | For internal use only. |
| TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS | For internal use only. |

## Return value

The **TmInitializeTransactionManager** routine returns STATUS_SUCCESS if the operation succeeds.