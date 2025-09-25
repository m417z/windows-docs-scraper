# SYNCMGRFLAG enumeration

## Description

The **SYNCMGRFLAG** enumeration values are used in the [ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize) method to indicate how the synchronization event was initiated.

## Constants

### `SYNCMGRFLAG_CONNECT:0x1`

Synchronization was initiated by a network connect event.

### `SYNCMGRFLAG_PENDINGDISCONNECT:0x2`

Synchronization was initiated by a pending network disconnect event.

### `SYNCMGRFLAG_MANUAL:0x3`

Synchronization was initiated manually by the end user.

### `SYNCMGRFLAG_IDLE:0x4`

Synchronization was programmatically invoked.

### `SYNCMGRFLAG_INVOKE:0x5`

Synchronization was programmatically invoked.

### `SYNCMGRFLAG_SCHEDULED:0x6`

Synchronization was initiated by a scheduled update event.

### `SYNCMGRFLAG_EVENTMASK:0xff`

Synchronization mask value.

### `SYNCMGRFLAG_SETTINGS:0x100`

Synchronization was initiated for configuration purposes only in the **System Properties** dialog box.

### `SYNCMGRFLAG_MAYBOTHERUSER:0x200`

Interaction with the user is permitted. The application is allowed to show user interface elements and interact with the user. If this flag is not set, the application must not display any user interface elements other than using the [ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback) interface. If an application cannot complete the synchronization without displaying user interface elements and this flag is not set, the application fails the synchronization.

## See also

[ISyncMgrSynchronize::Initialize](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-initialize)