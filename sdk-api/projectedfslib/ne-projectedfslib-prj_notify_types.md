# PRJ_NOTIFY_TYPES enumeration

## Description

Types of notifications describing a change to the file or folder.

## Constants

### `PRJ_NOTIFY_NONE:0x00000000`

No notification.

### `PRJ_NOTIFY_SUPPRESS_NOTIFICATIONS:0x00000001`

If specified on virtualization instance start:

- This indicates that notifications should not be sent for the virtualization instance, or a specified subtree of the instance.

If specified in response to a notification:

- This indicates that notifications should not be sent for the specified file or folder until all handles to it are closed.

**Note** If this bit appears in a notification mask, it overrides all other bits in the mask. For example, a valid mask with this bit is treated as containing only PRJ_NOTIFY_SUPPRESS_NOTIFICATIONS.

### `PRJ_NOTIFY_FILE_OPENED:0x00000002`

If specified on virtualization instance start:

- This indicates that the provider should be notified when a handle is created to an existing file or folder.

If specified in response to a notification:

- This indicates that the provider should be notified if any further handles are created to the file or folder.

### `PRJ_NOTIFY_NEW_FILE_CREATED:0x00000004`

If specified on virtualization instance start:

- The provider should be notified when a new file or folder is created.

If specified in response to a notification:

- No effect.

### `PRJ_NOTIFY_FILE_OVERWRITTEN:0x00000008`

If specified on virtualization instance start:

- Indicates that the provider should be notified when an existing when an existing file is overwritten or superceded.

If specified in response to a notification:

- Indicates that the provider should be notified when the file or folder is overwritten or superceded.

### `PRJ_NOTIFY_PRE_DELETE:0x00000010`

If specified on virtualization instance start:

- Indicates that the provider should be notified when a file or folder is about to be deleted.

If specified in response to a notification:

- Indicates that the provider should be notified when a file or folder is about to be deleted.

### `PRJ_NOTIFY_PRE_RENAME:0x00000020`

If specified on virtualization instance start:

- Indicates that the provider should be notified when a file or folder is about to be renamed.

If specified in response to a notification:

- Indicates that the provider should be notified when a file or folder is about to be renamed.

### `PRJ_NOTIFY_PRE_SET_HARDLINK:0x00000040`

If specified on virtualization instance start:

- Indicates that the provider should be notified when a hard link is about to be created for a file.

If specified in response to a notification:

- Indicates that the provider should be notified when a hard link is about to be created for a file.

### `PRJ_NOTIFY_FILE_RENAMED:0x00000080`

If specified on virtualization instance start:

- Indicates that the provider should be notified that a file or folder has been renamed.

If specified in response to a notification:

- Indicates that the provider should be notified when a file or folder has been renamed.

### `PRJ_NOTIFY_HARDLINK_CREATED:0x00000100`

If specified on virtualization instance start:

- Indicates that the provider should be notified that a hard link has been created for a file.

If specified in response to a notification:

- Indicates that the provider should be notified that a hard link has been created for the file.

### `PRJ_NOTIFY_FILE_HANDLE_CLOSED_NO_MODIFICATION:0x00000200`

If specified on virtualization instance start:

- The provider should be notified when a handle is closed on a file/folder and the closing handle neither modified nor deleted it.

If specified in response to a notification:

- The provider should be notified when handles are closed for the file/folder and there were no modifications or deletions associated with the closing handle.

### `PRJ_NOTIFY_FILE_HANDLE_CLOSED_FILE_MODIFIED:0x00000400`

If specified on virtualization instance start:

- The provider should be notified when a handle is closed on a file/folder and the closing handle was used to modify it.

If specified in response to a notification:

- The provider should be notified when a handle is closed on the file/folder and the closing handle was used to modify it.

### `PRJ_NOTIFY_FILE_HANDLE_CLOSED_FILE_DELETED:0x00000800`

If specified on virtualization instance start:

- The provider should be notified when a handle is closed on a file/folder and it is deleted as part of closing the handle.

If specified in response to a notification:

- The provider should be notified when a handle is closed on the file/folder and it is deleted as part of closing the handle.

### `PRJ_NOTIFY_FILE_PRE_CONVERT_TO_FULL:0x00001000`

If specified on virtualization instance start:

- The provider should be notified when it is about to convert a placeholder to a full file.

If specified in response to a notification:

- The provider should be notified when it is about to convert the placeholder to a full file, assuming it is a placeholder and not already a full file.

### `PRJ_NOTIFY_USE_EXISTING_MASK:0xFFFFFFFF`

If specified on virtualization instance start:

- This value is not valid on virtualization instance start.

If specified in response to a notification:

- Continue to use the existing set of notifications for this file/folder.

## Remarks

ProjFS can send notifications of file system activity to a provider. When the provider starts a virtualization instance it specifies which notifications it wishes to receive. It may also specify a new set of notifications for a file when it is created or renamed. The provider must register a PRJ_NOTIFICATION_CB notification callback routine in the callbacks parameter of PrjStartVirtualizing in order to receive notifications.

ProjFS sends notifications for files and directories within an active virtualization root. That is, ProjFS will send notifications for the virtualization root and its descendants. Symbolic links and junctions within the virtualization root are not traversed when determining what constitutes a descendant of the virtualization root.

ProjFS sends notifications only for the primary data stream of a file. ProjFS does not send notifications for operations on alternate data streams.

ProjFS does not send notifications for an inactive virtualization instance. A virtualization instance is inactive if any one of the following is true:

- The provider has not yet started it by calling [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing).
- The provider has stopped the instance by calling [PrjStopVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstopvirtualizing).
- The provider process has exited
The provider may specify which notifications it wishes to receive when starting a virtualization instance, or in response to a notification that allows a new notification mask to be set.

The provider specifies a default set of notifications that it wants ProjFS to send for the virtualization instance when it starts the instance. This set of notifications is provided in the NotificationMappings member of the options parameter of [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing), which may specify different notification masks for different subtrees of the virtualization instance.

The provider may choose to supply a different notification mask in response to a notification of file open, create, supersede/overwrite, or rename. ProjFS will continue to send these notifications for the given file until all handles to the file are closed. After that it will revert to the default set of notifications. Naturally if the default set of notifications does not specify that ProjFS should notify for open, create, etc., the provider will not get the opportunity to specify a different mask for those operations.