# PRJ_NOTIFICATION_CB callback function

## Description

Delivers notifications to the provider about file system operations.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**FilePathName** Identifies the path for the file or directory to which the notification pertains.

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

### `isDirectory` [in]

TRUE if the **FilePathName** field in *callbackData* refers to a directory, FALSE otherwise.

### `notification` [in]

A [PRJ_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_notification) value specifying the notification.

### `destinationFileName` [in, optional]

If **notification** is **PRJ_NOTIFICATION_PRE_RENAME**  or **PRJ_NOTIFICATION_PRE_SET_HARDLINK**, this points to a null-terminated Unicode string specifying the path, relative to the virtualization root, of the target of the rename or set-hardlink operation.

### `operationParameters` [in, out]

A pointer to a [PRJ_NOTIFICATION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_notification_parameters) union specifying extra parameters for certain values of *notification*:

**PRJ_NOTIFICATION_FILE_OPENED**, **PRJ_NOTIFICATION_NEW_FILE_CREATED**, or **PRJ_NOTIFICATION_FILE_OVERWRITTEN**

The fields of the **PostCreate** member are specified. These fields are:

**NotificationMask**

Upon return from the PRJ_NOTIFICATION_CB callback, the provider may specify a new set of notifications that it wishes to receive for the file here.

If the provider sets this value to 0, it is equivalent to specifying **PRJ_NOTIFY_USE_EXISTING_MASK**.

**PRJ_NOTIFICATION_FILE_RENAMED**

The fields of the **FileRenamed** member are specified. These fields are:

**NotificationMask**

Upon return from the PRJ_NOTIFICATION_CB callback, the provider may specify a new set of notifications that it wishes to receive for the file here.

If the provider sets this value to 0, it is equivalent to specifying **PRJ_NOTIFY_USE_EXISTING_MASK**.

**PRJ_NOTIFICATION_FILE_HANDLE_CLOSED_FILE_DELETED**

* The fields of the **FileDeletedOnHandleClose** member are specified. These fields are:

  **NotificationMask**

  If the provider registered for **PRJ_NOTIFY_FILE_HANDLE_CLOSED_FILE_MODIFIED** as well as **PRJ_NOTIFY_FILE_HANDLE_CLOSED_FILE_DELETED**, this field is set to TRUE if the file was modified before it was deleted.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The provider successfully processed the notification. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

An appropriate HRESULT error code if the provider fails the operation. For pre-operation notifications (operations with "PRE" in their name), if the provider returns a failure code ProjFS will fail the corresponding operation with the provided error code.

## Remarks

This callback is optional. If the provider does not supply an implementation of this callback, it will not receive notifications.

The provider registers for the notifications it wishes to receive when it calls [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing).