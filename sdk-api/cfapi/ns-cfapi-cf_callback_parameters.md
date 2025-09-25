# CF_CALLBACK_PARAMETERS structure

## Description

This structure contains callback-specific parameters such as file offset, length, flags, etc.

## Members

### `ParamSize`

_ParamSize_ is set based on the callback being performed.

| Callback | ParamSize Information |
|--------|--------|
| CF_CALLBACK_TYPE_FETCH_DATA | Set to the size of `FetchData` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_VALIDATE_DATA | Set to the size of `ValidateData` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_CANCEL_FETCH_DATA | Set to the size of `Cancel.FetchData` plus the size of two `ULONG`s. |
| CF_CALLBACK_TYPE_FETCH_PLACHOLDERS | Set to the size of `FetchPlaceholders` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_CANCEL_FETCH_PLACHOLDERS | Set to the size of two `ULONG`s. |
| CF_CALLBACK_TYPE_NOTIFY_FILE_OPEN_COMPLETION | Set to the size of `OpenCompletion` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_FILE_CLOSE_COMPLETION | set to the size of `CloseCompletion` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_DEHYDRATE | Set to the size of `Dehydrate` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_DEHYDRATE_COMPLETION | Set to the size of `DehydrateCompletion` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_DELETE | Set to the size of `Delete` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_DELETE_COMPLETION | Set to the size of `DeleteCompletion` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_RENAME | Set to the size of `Rename` plus the size of a `ULONG`. |
| CF_CALLBACK_TYPE_NOTIFY_RENAME_COMPLETION | Set to the size of `RenameCompletion` plus the size of a `ULONG`. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Cancel`

### `DUMMYUNIONNAME.Cancel.Flags`

_Flags_ can be set to the following flags:

- **CF_CALLBACK_CANCEL_FLAG_IO_TIMEOUT** is set if the user request is cancelled as a result of the expiration of the 60 seconds timer.
- **CF_CALLBACK_CANCEL_FLAG_IO_ABORTED** is set if the user request is cancelled as a result of the user explicitly terminating the hydration from app-initiated download toast.

### `DUMMYUNIONNAME.Cancel.DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Cancel.DUMMYUNIONNAME.FetchData`

### `DUMMYUNIONNAME.Cancel.DUMMYUNIONNAME.FetchData.FileOffset`

The offset, in bytes, for specifying the range of file data that is no longer required. Note this may match the **RequiredFileOffset** from the corresponding fetch, but may also be a subset. If it is a subset, then data outside of the cancel range is still needed, for example to satisfy outstanding I/O operations that arrived subsequently.

### `DUMMYUNIONNAME.Cancel.DUMMYUNIONNAME.FetchData.Length`

The length, in bytes, of the file data that is no longer required. Note this may match the **RequiredLength** from the corresponding fetch, but may also be a subset. If it is a subset, then data outside of the cancel range is still needed, for example to satisfy outstanding I/O operations that arrived subsequently.

### `DUMMYUNIONNAME.FetchData`

### `DUMMYUNIONNAME.FetchData.Flags`

_Flags_ can be set to the following values:

- **CF_CALLBACK_FETCH_DATA_FLAG_RECOVER** is set if the callback is invoked as a result of previously interrupted hydration process, due to either unclean shutdown of the sync provider or power loss, etc.
- **CF_CALLBACK_FETCH_DATA_FLAG_EXPLICIT_HYDRATION** is set if the callback is invoked as a result of a call to [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder).

### `DUMMYUNIONNAME.FetchData.RequiredFileOffset`

The offset, in bytes, for specifying the range of file data that is absolutely needed by the filter in order to satisfy outstanding I/O requests.

### `DUMMYUNIONNAME.FetchData.RequiredLength`

The length, in bytes, of the file data that is absolutely needed by the filter in order to satisfy outstanding I/O requests.

### `DUMMYUNIONNAME.FetchData.OptionalFileOffset`

The offset, in bytes, provided as a hint as to a broader range of file data that could usefully be given to the platform, in case the sync provider prefers to give data in larger chunks. Usually the optional range will be the maximal contiguous range that is not currently present in the placeholder. This is optional and can be used if the sync provider prefers to work with larger segments of data.

### `DUMMYUNIONNAME.FetchData.OptionalLength`

The length, in bytes, provided as a hint as to a broader range of file data that could usefully be given to the platform, in case the sync provider prefers to give data in larger chunks. Usually the optional range will be the maximal contiguous range that is not currently present in the placeholder. This is optional and can be used if the sync provider prefers to work with larger segments of data.

A length of -1, denoted as `CF_EOF`, means infinity (i.e. to end of file).

There is no requirement for the sync provider to return all the data required at once. There is also no requirement for the sync provider to return the data within either the required range or optional range. The platform ensures under no circumstances will modified/unsynced file data get clobbered because of an invalid **CF_OPERATION_TYPE_TRANSFER_DATA** operation. However, the data returned must be 4KB aligned for both the offset and length unless the returned range ends on the end of the file, in which case the length is not required to be 4KB aligned if the range ends on or beyond the end of the file.

### `DUMMYUNIONNAME.FetchData.LastDehydrationTime`

The system time when the cloud file in question was dehydrated. It is a count of 100-nanosecond intervals since January 1, 1601.

### `DUMMYUNIONNAME.FetchData.LastDehydrationReason`

A member of the [CF_CALLBACK_DEHYDRATION_REASON](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_dehydration_reason) enumeration specifying the reason that the file was last dehydrated.

_LastDehydrationReason_ can be one of the following:

| Reason | Description |
|--------|--------|
| CF_CALLBACK_DEHYDRATE_REASON_NEVER | The cloud file has never been dehydrated after its creation. |
| CF_CALLBACK_DEHYDRATE_REASON_USER_MANUAL | User explicitly dehydrated the cloud file. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_PERIODIC | The platform aged out the cloud file based on user defined policies. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_LOWSPACE | The platform dehydrated the cloud file when experiencing low disk space on the volume where this file resides. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_UPGRADE | The platform dehydrated this file when reclaiming disk space in order to upgrade the OS. |

### `DUMMYUNIONNAME.ValidateData`

### `DUMMYUNIONNAME.ValidateData.Flags`

Data validation flags. **CF_CALLBACK_VALIDATE_DATA_FLAG_EXPLICIT_HYDRATION** is set if the callback is invoked as a result of a call to [CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder).

### `DUMMYUNIONNAME.ValidateData.RequiredFileOffset`

The offset, in bytes, for specifying the range of file data to validate.

### `DUMMYUNIONNAME.ValidateData.RequiredLength`

The length, in bytes, of the range of file data that needs to be validated. A length of -1, denoted as `CF_EOF`, means infinity (i.e. to end of file).

There is no requirement for the sync provider to acknowledge all the data required at once. There is also no requirement for the sync provider to acknowledge the data within either the required range. The platform ensures under no circumstances will modified/unsynced file data get clobbered because of an invalid **CF_OPERATION_TYPE_ACT_DATA** operation. However, the data acknowledged must be 4KB aligned for both the offset and length unless the returned range ends on the end of the file, in which case the length is not required to be 4KB aligned if the range ends on or beyond the end of the file.

### `DUMMYUNIONNAME.FetchPlaceholders`

### `DUMMYUNIONNAME.FetchPlaceholders.Flags`

This _Flags_ value should be set to **CF_CALLBACK_FETCH_PLACEHOLDERS_FLAG_NONE**.

### `DUMMYUNIONNAME.FetchPlaceholders.Pattern`

A standard Windows file pattern which may contain wildcard characters (`?`, `*`). Often the pattern will be `*` but it could be more specific. The sync provider is expected to begin transferring placeholder information for all files in the directory using **CF_OPERATION_TYPE_TRANSFER_PLACEHOLDERS**. The sync provider must transfer all placeholders matching the pattern but not necessarily in one shot, as a minimum requirement. The sync provider may additionally choose to transfer placeholders not matching the pattern.

### `DUMMYUNIONNAME.OpenCompletion`

### `DUMMYUNIONNAME.OpenCompletion.Flags`

Placeholder open completion flags. It can be set to one of the following two flags:

- **CF_CALLBACK_OPEN_COMPLETION_FLAG_PLACEHOLDER_UNKNOWN** is set if the placeholder metadata is corrupted.
- **CF_CALLBACK_OPEN_COMPLETION_FLAG_PLACEHOLDER_UNSUPPORTED** is set if the placeholder metadata is of an older and unsupported version.

### `DUMMYUNIONNAME.CloseCompletion`

### `DUMMYUNIONNAME.CloseCompletion.Flags`

Placeholder close completion flags. It can be set to **CF_CALLBACK_CLOSE_COMPLETION_FLAG_DELETED** if the placeholder is deleted as a result of the close.

### `DUMMYUNIONNAME.Dehydrate`

### `DUMMYUNIONNAME.Dehydrate.Flags`

Placeholder dehydration flags. It can be set to **CF_CALLBACK_DEHYDRATE_FLAG_BACKGROUND** if the dehydration request is initiated by a system background service.

### `DUMMYUNIONNAME.Dehydrate.Reason`

The _Reason_ is a member of the [CF_CALLBACK_DEHYDRATION_REASON](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_dehydration_reason) enumeration specifying the reason why the placeholder is being dehydrated. It can be one of the following values:

| Reason | Description |
|--------|--------|
| CF_CALLBACK_DEHYDRATE_REASON_USER_MANUAL | User explicitly asks to dehydrate the cloud file. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_INACTIVITY | The platform ages out the cloud file periodically based on user defined policies. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_LOW_SPACE | The platform is experiencing low disk space on the volume where this cloud file resides. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_OS_UPGRADE | The platform is reclaiming disk space in order to upgrade the OS. |

### `DUMMYUNIONNAME.DehydrateCompletion`

### `DUMMYUNIONNAME.DehydrateCompletion.Flags`

Placeholder dehydration completion flags. It can be set to the following values:

- **CF_CALLBACK_DEHYDRATE_COMPLETION_FLAG_BACKGROUND** is set if the dehydration request is initiated by a system background service.
- **CF_CALLBACK_DEHYDRATE_COMPLETION_FLAG_DEHYDRATED** is set if the placer was hydrated prior to the dehydration request.

### `DUMMYUNIONNAME.DehydrateCompletion.Reason`

The _Reason_ is a member of the [CF_CALLBACK_DEHYDRATION_REASON](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_dehydration_reason) enumeration specifying the reason why the placeholder was dehydrated. It can be one of the following values:

| Reason | Description |
|--------|--------|
| CF_CALLBACK_DEHYDRATE_REASON_USER_MANUAL | User explicitly asks to dehydrate the cloud file. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_INACTIVITY | The platform ages out the cloud file periodically based on user defined policies. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_LOW_SPACE | The platform is experiencing low disk space on the volume where this cloud file resides. |
| CF_CALLBACK_DEHYDRATE_REASON_SYSTEM_OS_UPGRADE | The platform is reclaiming disk space in order to upgrade the OS. |

### `DUMMYUNIONNAME.Delete`

### `DUMMYUNIONNAME.Delete.Flags`

Placeholder deletion flags. It is set to **CF_CALLBACK_DELETE_FLAG_NONE**.

### `DUMMYUNIONNAME.DeleteCompletion`

### `DUMMYUNIONNAME.DeleteCompletion.Flags`

Placeholder deletion complete flags. It is set to **CF_CALLBACK_DELETE_COMPLETION_FLAG_NONE**.

### `DUMMYUNIONNAME.Rename`

### `DUMMYUNIONNAME.Rename.Flags`

Rename placeholder flags. It can be set to the following values:

- **CF_CALLBACK_RENAME_FLAG_IS_DIRECTORY** is set if the placeholder is a directory.
- **CF_CALLBACK_RENAME_FLAG_SOURCE_IN_SCOPE** is set if the link to be renamed or moved is within a sync root managed by the sync process.
- **CF_CALLBACK_RENAME_FLAG_TARGET_IN_SCOPE** is set if the rename or move target is in the same sync root of the source path.

### `DUMMYUNIONNAME.Rename.TargetPath`

The full rename/move target path relative to the volume.

### `DUMMYUNIONNAME.RenameCompletion`

### `DUMMYUNIONNAME.RenameCompletion.Flags`

The rename completion placeholder flags. It is set to **CF_CALLBACK_RENAME_COMPLETION_FLAG_NONE**.

### `DUMMYUNIONNAME.RenameCompletion.SourcePath`

The full source link path relative to the volume.

## See also

[CfHydratePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder)

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)

[CF_CALLBACK_DEHYDRATION_REASON](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_dehydration_reason)