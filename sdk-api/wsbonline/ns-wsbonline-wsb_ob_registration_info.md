# WSB_OB_REGISTRATION_INFO structure

## Description

 The **WSB_OB_REGISTRATION_INFO** structure contains information to register a cloud backup provider with Windows Server Backup.

## Members

### `m_wszResourceDLL`

The complete path to the resource DLL where the provider name and icon resources can be loaded from.

### `m_guidSnapinId`

The snap-in identifier of the cloud backup provider to be registered with Windows Server Backup.

### `m_dwProviderName`

The resource identifier of the cloud backup provider name. This name will be shown in the Windows Server Backup MMC snap-in.

### `m_dwProviderIcon`

The resource identifier of the cloud backup provider icon. This icon will be shown in the Windows Server Backup MMC snap-in.

### `m_bSupportsRemoting`

A flag to indicate whether the cloud backup provider can communicate with a remote cloud backup provider engine.

## See also

[Cloud Backup Provider API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/wsb/windows-server-backup-api-structures)

[RegisterOnlineBackupWithWindowsServerBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbonline/nf-wsbonline-registeronlinebackupwithwindowsserverbackup)