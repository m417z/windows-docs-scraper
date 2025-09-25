# IFileSystemImage::put_FreeMediaBlocks

## Description

Sets the maximum number of blocks available for the image.

## Parameters

### `newVal` [in]

Number of blocks to use in creating the file system image.

By default, 332,800 blocks are used to create the file system image. This value assumes a capacity of 74 minutes of audio per 650MB disc.

To specify an infinite number of block, set *newVal* to zero.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_IMAGE_TOO_BIG** | Value specified for FreeMediaBlocks property is too small for estimated image size based on current data. <br><br>Value: 0xC0AAB121 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_FreeMediaBlocks](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_freemediablocks)