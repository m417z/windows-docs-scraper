# _MSiSCSI_PersistentLogins structure

## Description

The MSiSCSI_PersistentLogins structure contains the list of persistent target logon sessions.

## Members

### `PersistentLoginCount`

The number of persistent target logon sessions that the initiator manages.

### `Reserved`

Reserved for Microsoft use only.

### `PersistentLogins`

A variable length array of [ISCSI_Persistent_Login](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_iscsi_persistent_login) structures, each of which contains information that is associated with a particular persistent logon session that the initiator maintains.

## Remarks

Miniport drivers that manage iSCSI initiators automatically establish persistent logon sessions as soon as they are loaded into the storage driver stack. This guarantees that targets for which the initiator maintains persistent logon sessions will be available to the system as early in the startup process as possible. You must implement this class.

## See also

[ISCSI_Persistent_Login](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_iscsi_persistent_login)

[ISCSI_Persistent_Login WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-persistent-login-wmi-class)

[MSiSCSI_PersistentLogins WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-persistentlogins-wmi-class)