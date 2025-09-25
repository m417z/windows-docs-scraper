# GetVolumesFromDriveA function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetVolumesFromDrive** function retrieves the volume and drive letter for a given removable storage media drive.

## Parameters

### `pszDriveName` [in]

The name of the removable storage media drive.

### `VolumeNameBufferPtr` [out]

The volume that represents the removable storage media drive.

### `DriveLetterBufferPtr` [out]

The drive letter that represents the removable storage media drive.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function assumes there will be only zero or one partitions on a
removable disk, so there is at most one drive letter and one volume name.

> [!NOTE]
> The ntmsapi.h header defines GetVolumesFromDrive as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectinformation)

[Library Control Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)