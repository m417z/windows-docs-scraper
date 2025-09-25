# WSB_OB_STATUS_ENTRY structure

## Description

 The **WSB_OB_STATUS_ENTRY** structure contains status
information for one entry to be shown in the Windows Server Backup MMC snap-in.

## Members

### `m_dwIcon`

The resource identifier of the icon to be shown with the status entry. A value of zero indicates no icon is
to be shown.

### `m_dwStatusEntryName`

The resource identifier of the name of the status entry.

### `m_dwStatusEntryValue`

The resource identifier of the value of the status entry.

### `m_cValueTypePair`

The number of
[WSB_OB_STATUS_ENTRY_VALUE_TYPE_PAIR](https://learn.microsoft.com/windows/win32/api/wsbonline/ns-wsbonline-wsb_ob_status_entry_value_type_pair)
structures pointed to by the **m_rgValueTypePair** member.

### `m_rgValueTypePair`

The list of parameters used to expand the value string contained in the
**m_dwStatusEntryValue** member.

## Remarks

The resources indicated by the resource IDs contained in the **m_dwIcon**,
**m_dwStatusEntryName** and **m_dwStatusEntryValue** members will
be loaded from the same DLL provided by the cloud backup provider during its registration with Windows Server
Backup. For example, an entry name resource ID could point to the string "Total Backups:" or an
entry value resource ID could point to the string "%0 copies".

## See also

[Cloud Backup Provider API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/wsb/windows-server-backup-api-structures)

[WSB_OB_STATUS_ENTRY_VALUE_TYPE_PAIR](https://learn.microsoft.com/windows/win32/api/wsbonline/ns-wsbonline-wsb_ob_status_entry_value_type_pair)