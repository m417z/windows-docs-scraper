## Description

Contains common callback information such as the callback type, the user process that triggers the callback, and the basic information about the file on which the callback is requested.

## Members

### `StructSize`

The size of **CF_CALLBACK_INFO**.

### `ConnectionKey`

An opaque handle created by [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot) for a sync root managed by the sync provider. *ConnectionKey* is returned as a convenience so the sync provider doesn't need to manually track it.

### `CallbackContext`

Points to an opaque blob that the sync provider provides at the sync root connect time. *CallbackContext* is returned as a convenience so the sync provider doesn't need to manually track it.

### `VolumeGuidName`

GUID name of the volume on which the placeholder file/directory to be serviced resides. It is in the form: “\\?\Volume{GUID}”.

### `VolumeDosName`

DOS drive letter of the volume in the form of "X:" where **X** is the drive letter.

### `VolumeSerialNumber`

The serial number of the volume.

### `SyncRootFileId`

A 64 bit file system maintained, volume-wide unique ID of the sync root under which the placeholder file or directory to be serviced resides.

### `SyncRootIdentity`

Points to the opaque blob provided by the sync provider at the sync root registration time.

### `SyncRootIdentityLength`

The length, in bytes, of the *SyncRootIdentity*.

### `FileId`

A 64 bit file system maintained, volume-wide unique ID of the placeholder file or directory to be serviced.

### `FileSize`

The logical size of the placeholder file to be serviced. It is always `0` if the subject of the callback is a directory.

### `FileIdentity`

Points to the opaque blob that the sync provider provides at the placeholder creation/conversion/update time.

### `FileIdentityLength`

The length, in bytes, of *FileIdentity*.

### `NormalizedPath`

The absolute path of the placeholder file or directory to be serviced on the volume identified by VolumeGuidName/VolumeDosName. It starts from the root directory of the volume. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_callback_info#-remarks) section for more details.

### `TransferKey`

An opaque handle to the placeholder file/directory to be serviced. The sync provider must pass it back to the [CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute) call in order to perform the desired operation on the file/directory.

### `PriorityHint`

A numeric scale given to the sync provider to describe the relative priority of one fetch compared to another fetch, in order to provide the most responsive experience to the user. The values range from `0` (lowest possible priority) to `15` (highest possible priority), but otherwise the values have no specific meaning. The filter may adjust how it chooses priority hints according to conditions. The sync provider is free to use the hint however it chooses.

### `CorrelationVector`

An optional correlation vector.

### `ProcessInfo`

Points to a [CF_PROCESS_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_process_info) structure that contains the information about the user process that triggers this callback. It is present only if the sync provider specifies **CF_CONNECT_FLAG_REQUIRE_PROCESS_INFO** at the sync root connect time.

### `RequestKey`

An opaque id that uniquely identifies a cloud file operation on a particular cloud file as indicated by *TransferKey*. Sync providers don’t need to interpret this field. The only requirement on a sync provider is to transfer it as-is to [CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info).

## Remarks

A file name is considered normalized if all of the following are true:

- It contains the full directory path for the file, including the volume name, unless the user opened the file by file ID but does not have traverse privilege for the entire path. (For more information, see [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetfilenameinformation).)
- The volume name is the volume's non-persistent device object name (for example, "\Device\HarddiskVolume1").
- All short names are expanded to the equivalent long names.
- Any trailing ":$DATA" or "::$DATA" strings are removed from the stream name.
- All mount points are resolved.

## See also

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)

[CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute)

[CF_PROCESS_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_process_info)

[CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info)

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltgetfilenameinformation)