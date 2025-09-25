# IFileSystemImage::get_FreeMediaBlocks

## Description

Retrieves the maximum number of blocks available for the image.

## Parameters

### `pVal` [out]

Number of blocks to use in creating the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::put_FreeMediaBlocks](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_freemediablocks)

[IFilesystemImage::ChooseImageDefaults](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaults)

[IFilesystemImage::ChooseImageDefaultsForMediaType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaultsformediatype)