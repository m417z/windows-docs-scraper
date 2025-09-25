# SetupDestroyDiskSpaceList function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupDestroyDiskSpaceList** function destroys a disk-space list and releases the resources allocated to it.

## Parameters

### `DiskSpace` [in, out]

Handle to the disk-space list to be deconstructed.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCreateDiskSpaceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcreatediskspacelista)