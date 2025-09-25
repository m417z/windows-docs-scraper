## Description

**FILE_NOTIFY_INFORMATION** describes the changes to a directory. It's returned in response to an [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control) request with an **IRP_MN_NOTIFY_CHANGE_DIRECTORY** minor function code when [**DIRECTORY_NOTIFY_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_directory_notify_information_class) is DirectoryNotifyInformation.

## Members

### `NextEntryOffset`

The number of bytes that must be skipped to get to the next record. A value of zero indicates that this is the last record.

### `Action`

The type of change that has occurred. This member can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| FILE_ACTION_ADDED (0x00000001) | The file was added to the directory. |
| FILE_ACTION_REMOVED (0x00000002) | The file was removed from the directory. |
| FILE_ACTION_MODIFIED (0x00000003) | The file was modified. This can be a change in the time stamp or attributes. |
| FILE_ACTION_RENAMED_OLD_NAME (0x00000004) | The file was renamed and this is the old name. |
| FILE_ACTION_RENAMED_NEW_NAME (0x00000005) | The file was renamed and this is the new name. |
| FILE_ACTION_ADDED_STREAM (0x00000006) | A named stream was added to the file. |
| FILE_ACTION_REMOVED_STREAM (0x00000007) | A named stream was removed from the file. |
| FILE_ACTION_MODIFIED_STREAM (0x00000008) | A named stream was modified. The modification can be a change to the data or attributes of the named stream. |
| FILE_ACTION_REMOVED_BY_DELETE (0x00000009) | An object ID was removed because the file the object ID referred to was deleted. This notification is only sent when the directory being monitored is the special directory "\$Extend\$ObjId:$O:$INDEX_ALLOCATION". |
| FILE_ACTION_ID_NOT_TUNNELLED (0x0000000A) | An attempt to tunnel object ID information to a file being created or renamed failed because the object ID is in use by another file on the same volume. This notification is only sent when the directory being monitored is the special directory "\$Extend\$ObjId:$O:$INDEX_ALLOCATION". |
| FILE_ACTION_TUNNELLED_ID_COLLISION (0x0000000B) | An attempt to tunnel object ID information to a file being renamed failed because the file already has an object ID. This notification is only sent when the directory being monitored is the special directory "\$Extend\$ObjId:$O:$INDEX_ALLOCATION". |

### `FileNameLength`

The size of the file name portion of the record, in bytes. This value does not include the terminating null character.

### `FileName`

A variable-length field that contains the file name relative to the directory handle. The file name is in the Unicode character format and is not null-terminated.

If there is both a short and long name for the file, only one of these names will be returned, but it is unspecified which one.

## See also

[**DIRECTORY_NOTIFY_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_directory_notify_information_class)

[**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[**ZwNotifyChangeDirectoryFileEx**](https://learn.microsoft.com/previous-versions/mt812581(v=vs.85))