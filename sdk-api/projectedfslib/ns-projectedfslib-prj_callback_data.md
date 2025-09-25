# PRJ_CALLBACK_DATA structure

## Description

Defines the standard information passed to a provider for every operation callback.

## Members

### `Size`

Size in bytes of this structure. The provider must not attempt to access any field of this structure that is located beyond this value.

### `Flags`

Callback-specific flags.

### `NamespaceVirtualizationContext`

Opaque handle to the virtualization instance that is sending the callback.

### `CommandId`

A value that uniquely identifies a particular invocation of a callback. The provider uses this value:

* In calls to [PrjCompleteCommand](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjcompletecommand) to signal completion of a callback from which it earlier returned HRESULT_FROM_WIN32(ERROR_IO_PENDING).
* When ProjFS sends a [PRJ_CANCEL_COMMAND_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_cancel_command_cb) callback. The commandId in the *PRJ_CANCEL_COMMAND_CB* call identifies an earlier invocation of a callback that the provider should cancel.

### `FileId`

A value that uniquely identifies the file handle for the callback.

### `DataStreamId`

A value that uniquely identifies an open data stream for the callback.

### `FilePathName`

The path to the target file. This is a null-terminated string of Unicode characters. This path is always specified relative to the virtualization root.

### `VersionInfo`

Version information if the target of the callback is a placeholder or partial file.

### `TriggeringProcessId`

The process identifier for the process that triggered this callback. If this information is not available, this will be 0. Callbacks that supply this information include: [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb),
[PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb), and
[PRJ_NOTIFICATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_notification_cb).

### `TriggeringProcessImageFileName`

A null-terminated Unicode string specifying the image file name corresponding to TriggeringProcessId. If TriggeringProcessId is 0 this will be NULL.

### `InstanceContext`

A pointer to context information defined by the provider. The provider passes this context in the instanceContext parameter of [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing).

If the provider did not specify such a context, this value will be NULL.