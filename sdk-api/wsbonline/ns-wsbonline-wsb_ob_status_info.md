# WSB_OB_STATUS_INFO structure

## Description

 The **WSB_OB_STATUS_INFO** structure contains information to update the cloud backup provider status in the Windows Server Backup MMC snap-in.

## Members

### `m_guidSnapinId`

The snap-in identifier of the cloud backup provider registered with Windows Server Backup.

### `m_cStatusEntry`

The number of status entries contained in the **m_rgStatusEntry** member. The maximum number of entries allowed is five.

### `m_rgStatusEntry`

A pointer to one or more [WSB_OB_STATUS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wsbonline/ns-wsbonline-wsb_ob_status_entry) structures, each containing cloud backup provider status information for one entry to be shown in the Windows Server Backup MMC snap-in.

## See also

[Cloud Backup Provider API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/wsb/windows-server-backup-api-structures)

[UpdateOBStatusInWindowsServerBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbonline/nf-wsbonline-updateobstatusinwindowsserverbackup)

[WSB_OB_STATUS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wsbonline/ns-wsbonline-wsb_ob_status_entry)