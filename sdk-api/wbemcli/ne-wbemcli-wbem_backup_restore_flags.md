# WBEM_BACKUP_RESTORE_FLAGS enumeration

## Description

Contains flags used for the [IWbemBackupRestore::Restore](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbembackuprestore-restore) method and the [IWbemBackupRestoreEx::Restore](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa391421(v=vs.85)) method.

## Constants

### `WBEM_FLAG_BACKUP_RESTORE_DEFAULT:0`

Does not shut down active clients; returns an error if there are any.

### `WBEM_FLAG_BACKUP_RESTORE_FORCE_SHUTDOWN:1`

Shuts down any active clients.