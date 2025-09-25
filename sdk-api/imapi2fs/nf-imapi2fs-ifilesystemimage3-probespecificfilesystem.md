# IFileSystemImage3::ProbeSpecificFileSystem

## Description

Determines if a specific file system on the current media is appendable through the IMAPI.

## Parameters

### `fileSystemToProbe` [in]

The file system on the current media to probe.

### `isAppendable` [out, ref, retval]

A **VARIANT_BOOL** value specifying if the specified file system is appendable.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFileSystemImage3](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage3)