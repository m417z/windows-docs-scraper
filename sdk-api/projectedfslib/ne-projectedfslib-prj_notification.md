# PRJ_NOTIFICATION enumeration

## Description

A notification value specified when sending the [PRJ_NOTIFICATION_CB callback](https://learn.microsoft.com/windows/win32/api/projectedfslib/nc-projectedfslib-prj_notification_cb).

## Constants

### `PRJ_NOTIFICATION_FILE_OPENED:0x00000002`

- Indicates that a handle has been created to an existing file or folder.
- The provider can specify a new notification mask for this file or folder when responding to the notification.

### `PRJ_NOTIFICATION_NEW_FILE_CREATED:0x00000004`

- A new file or folder has been created.
- The provider can specify a new notification mask for this file or folder when responding to the notification.

### `PRJ_NOTIFICATION_FILE_OVERWRITTEN:0x00000008`

- An existing file has been overwritten or superceded.
- The provider can specify a new notification mask for this file or folder when responding to the notification.

### `PRJ_NOTIFICATION_PRE_DELETE:0x00000010`

- A file or folder is about to be deleted.
- If the provider returns an error HRESULT code from the callback, the delete will not take effect.

### `PRJ_NOTIFICATION_PRE_RENAME:0x00000020`

- A file or folder is about to be renamed.
- If the provider returns an error HRESULT code from the callback, the rename will not take effect.
- If the callbackData->FilePathName parameter of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) is an empty string, this indicates that the rename is moving the file/directory from outside the virtualization instance. In that case, this notification will always be sent if the provider has registered a [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) callback, even if the provider did not specify this bit when registering the subtree containing the destination path. However if the provider specified PRJ_NOTIFICATION_SUPPRESS_NOTIFICATIONS when registering the subtree containing the destination path, the notification will be suppressed.
- If the destinationFileName parameter of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) is an empty string, this indicates that the rename is moving the file/folder out of the virtualization instance.
- If both the callbackData->FilePathName and destinationFileName parameters of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) are non-empty strings, this indicates that the rename is within the virtualization instance. If the provider specified different notification masks for the source and destination paths in the NotificationMappings member of the options parameter of [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing), then this notification will be sent if the provider specified this bit when registering either the source or destination paths.

### `PRJ_NOTIFICATION_PRE_SET_HARDLINK:0x00000040`

- A hard link is about to be created for the file.
- If the provider returns an error HRESULT code from the callback, the hard link operation will not take effect.
- If the callbackData->FilePathName parameter of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) is an empty string, this indicates that the hard link name will be created inside the virtualization instance, i.e. a new hard link is being created inside the virtualization instance to a file that exists outside the virtualization instance. In that case, this notification will always be sent if the provider has registered a [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) callback, even if the provider did not specify this bit when registering the subtree where the new hard link name will be. However if the provider specified PRJ_NOTIFICATION_SUPPRESS_NOTIFICATIONS when registering the subtree containing the destination path, the notification will be suppressed.
- If the destinationFileName parameter of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) is an empty string, this indicates that the hard link name will be created outside the virtualization instance, i.e. a new hard link is being created outside the virtualization instance for a file that exists inside the virtualization instance.
- If both the callbackData->FilePathName and destinationFileName parameters of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) are non-empty strings, this indicates that the new hard link will be created within the virtualization instance for a file that exists within the virtualization instance. If the provider specified different notification masks for the source and destination paths in the NotificationMappings member of the options parameter of [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing), then this notification will be sent if the provider specified this bit when registering either the source or destination paths.

### `PRJ_NOTIFICATION_FILE_RENAMED:0x00000080`

- Indicates that a file/folder has been renamed. The file/folder may have been moved into the virtualization instance.
- If the callbackData->FilePathName parameter of PRJ_NOTIFICATION_CB is an empty string, this indicates that the rename moved the file/directory from outside the virtualization instance. In that case ProjFS will always send this notification if the provider has registered a PRJ_NOTIFICATION_CB callback, even if the provider did not specify this bit when registering the subtree containing the destination path.
- If the destinationFileName parameter of PRJ_NOTIFICATION_CB is an empty string, this indicates that the rename moved the file/directory out of the virtualization instance.
- If both the callbackData->FilePathName and destinationFileName parameters of PRJ_NOTIFICATION_CB are non-empty strings, this indicates that the rename was within the virtualization instance. If the provider specified different notification masks for the source and destination paths in the NotificationMappings member of the options parameter of PrjStartVirtualizing, then ProjFS will send this notification if the provider specified this bit when registering either the source or destination paths.
- The provider can specify a new notification mask for this file/directory when responding to the notification.

### `PRJ_NOTIFICATION_HARDLINK_CREATED:0x00000100`

- Indicates that a hard link has been created for the file.
- If the callbackData->FilePathName parameter of PRJ_NOTIFICATION_CB is an empty string, this indicates that the hard link name was created inside the virtualization instance, i.e. a new hard link was created inside the virtualization instance to a file that exists outside the virtualization instance. In that case ProjFS will always send this notification if the provider has registered a PRJ_NOTIFICATION_CB callback, even if the provider did not specify this bit when registering the subtree where the new hard link name will be.
- If the destinationFileName parameter of PRJ_NOTIFICATION_CB is an empty string, this indicates that the hard link name was created outside the virtualization instance, i.e. a new hard link was created outside the virtualization instance for a file that exists inside the virtualization instance.
- If both the callbackData->FilePathName and destinationFileName parameters of PRJ_NOTIFICATION_CB are non-empty strings, this indicates that the a new hard link was created within the virtualization instance for a file that exists within the virtualization instance. If the provider specified different notification masks for the source and destination paths in the NotificationMappings member of the options parameter of PrjStartVirtualizing, then ProjFS will send this notification if the provider specified this bit when registering either the source or destination paths.

### `PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_NO_MODIFICATION:0x00000200`

- A handle has been closed on the file/folder, and the file's content was not modified while the handle was open, and the file/folder was not deleted

### `PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_MODIFIED:0x00000400`

- A handle has been closed on the file, and that the file's content was modified while the handle was open.

### `PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_DELETED:0x00000800`

- A handle has been closed on the file/folder, and that it was deleted as part of closing the handle.
- If the provider also registered to receive PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_MODIFIED notifications, and the file was modified using the handle whose close resulted in deleting the file, then the operationParameters->FileDeletedOnHandleClose.IsFileModified parameter of [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) will be TRUE. This applies only to files, not directories

### `PRJ_NOTIFICATION_FILE_PRE_CONVERT_TO_FULL:0x00001000`

- The file is about to be expanded from a placeholder to a full file, i.e. its contents are likely to be modified.
- If the provider returns an error HRESULT code from the callback, the file will not be expanded to a full file, and the I/O that triggered the conversion will fail.
- If there are multiple racing I/Os that would expand the same file, the provider will receive this notification value only once for the file.