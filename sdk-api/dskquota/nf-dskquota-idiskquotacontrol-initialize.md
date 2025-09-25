# IDiskQuotaControl::Initialize

## Description

Initializes a new **DiskQuotaControl** object by opening the NTFS file system volume with the requested access rights. The return value indicates whether the volume supports NTFS file system disk quotas and whether the caller has sufficient access rights.

## Parameters

### `pszPath` [in]

The path to the volume root, such as C:\ or \\*yourcomputer*.

### `bReadWrite` [in]

If this value is **TRUE**, the volume is opened in read/write mode. If this value is **FALSE**, the volume is opened in read-only mode. To write data to the quota file, you must specify **TRUE**, and the call to this method must return successfully.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_BAD_PATHNAME** | The requested path name is invalid. |
| **ERROR_FILE_NOT_FOUND** | The requested file or object is not found. |
| **ERROR_INITIALIZED** | The controller object has already been initialized. Multiple initialization is not allowed. |
| **ERROR_INVALID_NAME** | The requested file path is invalid. |
| **ERROR_NOT_SUPPORTED** | The file system does not support quotas. |
| **ERROR_PATH_NOT_FOUND** | The requested file path is not found. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[GetVolumePathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumepathnamew)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)