# IWbemBackupRestore::Restore

## Description

The **IWbemBackupRestore::Restore** method deletes the contents of the current repository and restores them with the contents of a previously specified backup.

Because Windows Management Instrumentation (WMI) is the server for this interface and must be stopped to complete this operation successfully, the COM connection is broken if this call is successful.

## Parameters

### `strRestoreFromFile` [in]

Constant, null-terminated string of 16-bit Unicode characters that contains the file name of the file to be restored. The specified file should point to a file previously created with
[IWbemBackupRestore::Backup](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbembackuprestore-backup).

### `lFlags` [in]

One of the following flags from the [WBEM_BACKUP_RESTORE_FLAGS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_backup_restore_flags) enumeration.

#### WBEM_FLAG_BACKUP_RESTORE_DEFAULT

Does not shut down active clients; returns an error if there are any.

#### WBEM_FLAG_BACKUP_RESTORE_FORCE_SHUTDOWN

Shuts down any active clients.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within the **HRESULT**.

## Remarks

The default mode is the same as setting the force-mode flag, which breaks all active connections. This results in remote procedure call (RPC) errors from active COM connections to WMI—until new connections are established.

#### Examples

The following C++ example shows how to call the **IWbemBackupRestore::Restore** method.

```cpp
// The pInt variable is of type IWbemBackupRestore*
pInt->Restore(
        L"c:\\\\Windows\\System32\\wbem\\repository\\back.x",
        WBEM_FLAG_BACKUP_RESTORE_FORCE_SHUTDOWN
      );
```