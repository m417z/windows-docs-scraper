# FltGetVolumeGuidName function

## Description

**FltGetVolumeGuidName** gets the volume name for a given volume, in volume globally unique identifier (GUID) format.

## Parameters

### `Volume` [in]

Opaque pointer for the volume. Must be a local file system volume. This parameter is required and cannot be **NULL**.

### `VolumeGuidName` [in/out, optional]

Pointer to a caller-allocated [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that receives the volume's GUID name when STATUS_SUCCESS is returned. Be aware that pool for **VolumeGuidName->Buffer** is also caller-allocated.

If **VolumeGuidName** is **NULL** and **BufferSizeNeeded** is not **NULL**, **FltGetVolumeGuidName** stores the buffer size needed for the requested volume GUID in the **BufferSizeNeeded** parameter and returns STATUS_BUFFER_TOO_SMALL. See Remarks.

### `BufferSizeNeeded` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the requested volume GUID name. This parameter is optional and can be **NULL**; however, it must be non-**NULL** if **VolumeGuidName** is **NULL** so that **FltGetVolumeGuidName** can store the buffer size needed for the requested volume GUID.

## Return value

**FltGetVolumeGuidName** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_TOO_SMALL | The buffer pointed to by **VolumeGuidName** is **NULL** or too small to hold the volume GUID. If the caller provides a non-**NULL** value for **BufferSizeNeeded**, **FltGetVolumeGuidName** stores the required buffer size in **BufferSizeNeeded**. This is considered an error code since the volume GUID name was not retrieved. |
| STATUS_INSUFFICIENT_RESOURCES | **FltGetVolumeGuidName** encountered a pool allocation failure. This is an error code. |
| STATUS_INVALID_DEVICE_REQUEST | The **Volume** parameter is a handle for a network volume. This is an error code. |
| STATUS_FLT_VOLUME_NOT_FOUND | No matching volume was found. This is an error code. |

## Remarks

The returned volume GUID name is expressed in the following format:

**\\??\Volume{***GUID***}**

where *GUID* is a globally unique identifier that identifies the volume. This format, which is the same as that used by the mount manager, is described in [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

If **BufferSizeNeeded** is unknown, call **FltGetVolumeGuidName** twice:

- On the first call, set **VolumeGuidName** to **NULL** and **BufferSizeNeeded** to non-**NULL**. **FltGetVolumeGuidName** will store the number of bytes needed for the volume name GUID in **BufferSizeNeeded** and return STATUS_BUFFER_TOO_SMALL.
- On the second call, set **VolumeGuidName** to point to a structure that is the size of the **BufferSizeNeeded** value returned in the first call.

**FltGetVolumeGuidName** cannot safely be called from a pre-mount or post-mount callback. It cannot safely be called because even when the post-mount callback is called, the mount processing has not been completed by the I/O manager, and this causes a deadlock with the mount manager in certain cases.

On Windows Vista and later, a minifilter driver can safely call **FltGetVolumeGuidName** from its *InstanceSetupCallback* routine ([**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)) because the callback is called on the first I/O operation for a new volume after all of the mount processing is completed.

On Windows operating systems earlier than Windows Vista, **FltGetVolumeGuidName** cannot safely be called from an *InstanceSetupCallback* routine because the mount manager might issue a file I/O operation while holding a lock, which can cause a deadlock.

It is important to note that the volume GUID is not the same as the volume object ID. The *volume GUID*, or *unique volume name*, is a file system-independent value; it is assigned to the underlying storage volume by the mount manager. The *volume object ID* is assigned to the file system volume by the file system.

To get the volume object ID for a volume, call [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), specifying **FileFsObjectIdInformation** for the *FsInformationClass* parameter.

**FltGetVolumeGuidName** is roughly equivalent to the Win32 **GetVolumeNameForVolumeMountPoint** function. (**GetVolumeNameForVolumeMountPoint** is documented in the Microsoft Windows SDK.)

## See also

[**FILE_FS_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_objectid_information)

[**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)