# IFileSystemImage::put_VolumeName

## Description

Sets the volume name for this file system image.

## Parameters

### `newVal` [in]

String that contains the volume name for this file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_VOLUME_NAME** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |

## Remarks

The string is limited to 15 characters. For ISO 9660 discs, the volume name can use the following characters:

* "A" through "Z"
* "0" through "9"
* "_" (underscore)

For Joliet and UDF discs, the volume name can use the following characters:

* "a" through "z"
* "A" through "Z"
* "0" through "9"
* "." (period)
* "_" (underscore)

If you do not specify a volume name, a default volume name is generated using the system date and time when the result object is created.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_ImportedVolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_importedvolumename)

[IFileSystemImage::get_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_volumename)