# PRJ_NOTIFICATION_PARAMETERS structure

## Description

Extra parameters for notifications.

## Members

### `PostCreate`

### `PostCreate.NotificationMask`

Upon return from the [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) callback, the provider may specify a new set of notifications that it wishes to receive for the file here. If the provider sets this value to 0, it is equivalent to specifying **PRJ_NOTIFICATION_USE_EXISTING_MASK**.

### `FileRenamed`

### `FileRenamed.NotificationMask`

Upon return from the [PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb) callback, the provider may specify a new set of notifications that it wishes to receive for the file here. If the provider sets this value to 0, it is equivalent to specifying **PRJ_NOTIFICATION_USE_EXISTING_MASK**.

### `FileDeletedOnHandleClose`

### `FileDeletedOnHandleClose.IsFileModified`

If the provider registered for **PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_MODIFIED** as well as **PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_DELETED**, this field is set to TRUE if the file was modified before it was deleted.