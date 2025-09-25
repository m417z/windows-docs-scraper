# IFileSystemImage::put_StageFiles

## Description

Determines if the files being added to the file system image should be staged before the burn.

## Parameters

### `newVal` [in]

Set to VARIANT_TRUE to force files added to the file system image to be staged in one or more stage files before burning. Otherwise, set to VARIANT_FALSE if staging is not required and higher performance is desired.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

"Staging" is a process in which an image is created on the hard-drive, containing all files to be burned, prior to the initiation of the burn operation.

Setting this this property to **VARIANT_TRUE** will only affect files that are added after the property is set: those files will always be staged. Files that were not staged prior to a specified property value of **VARIANT_TRUE**, will not be staged.

By specifying **VARIANT_FALSE**, the file system image creation process is optimized in two ways:

* Less time is required for image generation
* Less space is consumed on a local disk by IMAPI

However, in order to avoid buffer underrun problems during burning, a certain minimum throughput is required for read operations on non-staged files. In the event that file accessibility or throughput may not meet the requirements of the burner, IMAPI enforces file staging regardless of the specified property value. For example, file staging is enforced for source files from removable storage devices, such as USB Flash Disk.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_StageFiles](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_stagefiles)