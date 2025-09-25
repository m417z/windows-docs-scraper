# RegisterOnlineBackupWithWindowsServerBackup function

## Description

The **RegisterOnlineBackupWithWindowsServerBackup** function registers a cloud backup provider with Windows Server Backup.

## Parameters

### `pOBRegistrationInfo` [in]

Pointer to a [WSB_OB_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/wsbonline/ns-wsbonline-wsb_ob_registration_info) structure.

## Return value

The return values listed here are in addition to the normal **HRESULT**s that may be returned at any time
from the function.

## Remarks

If any other cloud backup provider is already registered with Windows Server Backup, [DeregisterOnlineBackupFromWindowsServerBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbonline/nf-wsbonline-deregisteronlinebackupfromwindowsserverbackup) must be called before calling **RegisterOnlineBackupWithWindowsServerBackup**.

## See also

[Cloud Backup Provider API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/wsb/windows-server-backup-api-functions)

[WSB_OB_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/wsbonline/ns-wsbonline-wsb_ob_registration_info)