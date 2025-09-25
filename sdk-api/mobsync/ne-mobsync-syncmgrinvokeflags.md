# SYNCMGRINVOKEFLAGS enumeration

## Description

The
**SYNCMGRINVOKEFLAGS** enumeration value specifies how the Sync Manager is to be invoked in the
[ISyncMgrSynchronizeInvoke::UpdateItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateitems) method.

## Constants

### `SYNCMGRINVOKE_STARTSYNC:0x2`

Immediately start the synchronization without displaying the **Choice** dialog box.

### `SYNCMGRINVOKE_MINIMIZED:0x4`

Indicates that the **Choice** dialog should be minimized by default.

## See also

[ISyncMgrSynchronizeInvoke::UpdateItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizeinvoke-updateitems)