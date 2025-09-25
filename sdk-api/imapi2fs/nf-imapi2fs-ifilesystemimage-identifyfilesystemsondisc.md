# IFileSystemImage::IdentifyFileSystemsOnDisc

## Description

Retrieves a list of the different types of file systems on the optical media.

## Parameters

### `discRecorder` [in, optional]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device that contains the media. If this parameter is **NULL**, the *discRecorder* specified in [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) will be used.

### `fileSystems` [out]

One or more files systems on the disc. For possible values, see [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

Client applications can call [IFileSystemImage::GetDefaultFileSystemForImport](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-getdefaultfilesystemforimport) with the value returned by this method to determine the type of file system to import.

## See also

[FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession)