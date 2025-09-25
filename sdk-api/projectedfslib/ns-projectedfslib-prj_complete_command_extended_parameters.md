# PRJ_COMPLETE_COMMAND_EXTENDED_PARAMETERS structure

## Description

Specifies parameters required for completing certain callbacks.

## Members

### `CommandType`

The type of command.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Notification`

### `DUMMYUNIONNAME.Notification.NotificationMask`

A new set of notifications the provider wishes to receive.

### `DUMMYUNIONNAME.Enumeration`

### `DUMMYUNIONNAME.Enumeration.DirEntryBufferHandle`

An opaque handle to a directory entry buffer. This must be the value passed in the dirEntryBufferHandle parameter of the [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callback being completed.

## Remarks

For any callback except [PRJ_CANCEL_COMMAND_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_cancel_command_cb), the provider may opt to process the callback asynchronously. To do so it returns HRESULT_FROM_WIN32(ERROR_IO_PENDING) from the callback. Once the provider has finished processing the callback.

If the provider calls this function for the commandId passed by the [PRJ_CANCEL_COMMAND_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_cancel_command_cb) callback it is not an error, however it is a no-op because the I/O that caused the callback invocation identified by commandId has already ended.