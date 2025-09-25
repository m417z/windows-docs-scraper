# GetStorageDependencyInformation function

## Description

Returns the relationships between virtual hard disks (VHDs) or CD or DVD image file (ISO) or the
volumes contained within those disks and their parent disk or volume.

## Parameters

### `ObjectHandle` [in]

A handle to a volume or root directory if the *Flags* parameter does not specify
the **GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE** flag. For information on how to open a
volume or root directory, see the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

If the *Flags* parameter specifies the
**GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE** flag, this handle should be a handle to a
disk.

### `Flags` [in]

A valid combination of
[GET_STORAGE_DEPENDENCY_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-get_storage_dependency_flag) values.

### `StorageDependencyInfoSize` [in]

Size, in bytes, of the buffer that the *StorageDependencyInfo* parameter refers
to.

### `StorageDependencyInfo` [in, out]

A pointer to a buffer to receive the populated
[STORAGE_DEPENDENCY_INFO](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-storage_dependency_info) structure, which is a
variable-length structure.

### `SizeUsed` [in, out, optional]

An optional pointer to a **ULONG** that receives the size used.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS** and the
*StorageDependencyInfo* parameter contains the requested dependency information.

If the function fails, the return value is an error code and the
*StorageDependencyInfo* parameter is undefined. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

CD and DVD image files (ISO) are not supported before Windows 8 and
Windows Server 2012.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))