# SYNCMGR_HANDLER_POLICIES enumeration

## Description

Enumerates policies specified by a sync handler that deviate from the default policy.

## Constants

### `SYNCMGR_HPM_NONE:0`

No handler policy flags are set.

### `SYNCMGR_HPM_PREVENT_ACTIVATE:0x1`

Activation of the handler is not supported at the time of the call. This value can be used by a handler to implement support for group policy that prevents the handler from being activated. If this value is set, the **Setup** task is not be shown in the Setup Sync folder when this handler is selected. The handler should provide a comment—returned from its implementation of [ISyncMgrHandlerInfo::GetComment](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-getcomment)—to let the user know why the **Setup** task is not available. Most handlers should not set this value.

### `SYNCMGR_HPM_PREVENT_DEACTIVATE:0x2`

Deactivation of the handler is not supported at the time of the call. This value can be used by a handler to implement support for group policy that prevents the handler from being deactivated. If this value is set, the **Delete** task is not shown in the Sync Center folder when this handler is selected. The handler should provide a comment—returned from its implementation of [ISyncMgrHandlerInfo::GetComment](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-getcomment)—to let the user know why the **Setup** task is not available. Most handlers should not set this value.

### `SYNCMGR_HPM_PREVENT_ENABLE:0x4`

The handler normally supports enable, but cannot be enabled because of handler policy. If this flag is set, the **Enable** option will not be displayed on the context menu.

### `SYNCMGR_HPM_PREVENT_DISABLE:0x8`

The handler normally supports disable, but cannot be enabled because of handler policy. If this flag is set, the **Disable** option will not be displayed on the context menu.

### `SYNCMGR_HPM_PREVENT_START_SYNC:0x10`

The handler normally supports sync, but cannot be synchronized because of handler policy. If this flag is set, the **Start Sync** option will not be displayed on the context menu or the command bar.

### `SYNCMGR_HPM_PREVENT_STOP_SYNC:0x20`

The handler normally supports sync, but cannot be synchronized because of handler policy. If this flag is set, the **Stop Sync** option will not be displayed on the context menu or the command bar.

### `SYNCMGR_HPM_DISABLE_ENABLE:0x100`

The handler normally supports enable, but cannot be enabled at the time of the call. The **Enable** option will be displayed but will be disabled.

### `SYNCMGR_HPM_DISABLE_DISABLE:0x200`

The handler normally supports disable, but cannot be disabled at the time of the call. The **Disable** option will be displayed but will be disabled.

### `SYNCMGR_HPM_DISABLE_START_SYNC:0x400`

The handler normally supports syncing, but cannot be synchronized at the time of the call. The **Start Sync** option will be displayed but will be disabled.

### `SYNCMGR_HPM_DISABLE_STOP_SYNC:0x800`

The handler normally supports cancel, but cannot be canceled at the time of the call. The **Stop Sync** option will be displayed but will be disabled.

### `SYNCMGR_HPM_DISABLE_BROWSE:0x1000`

The handler normally supports cancel, but cannot be canceled at the time of the call. The **Browse** option will be displayed but will be disabled.

### `SYNCMGR_HPM_DISABLE_SCHEDULE:0x2000`

The handler normally supports cancel, but cannot be canceled at the time of the call. The **Show Schedule** option will be displayed but will be disabled.

### `SYNCMGR_HPM_HIDDEN_BY_DEFAULT:0x10000`

The handler should be hidden from the user unless the **Show Hidden Files** option has been enabled. This policy only applies the first time that the handler is loaded. After that, the hidden state is maintained by Sync Center and can be changed by the user through the property sheet. The hidden state is available in the folder UI as the System.Sync.Hidden (PKEY_Sync_Hidden) property.

### `SYNCMGR_HPM_BACKGROUND_SYNC_ONLY`

The user is not offered **Sync** and **Stop** tasks in the UI. This is equivalent to `SYNCMGR_HPM_PREVENT_START_SYNC | SYNCMGR_HPM_PREVENT_STOP_SYNC`.

### `SYNCMGR_HPM_VALID_MASK:0x12f3f`

A mask used to retrieve valid [SYNCMGR_HANDLER_POLICIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flags.