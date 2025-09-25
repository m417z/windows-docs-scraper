# IFileSystemImage::ChooseImageDefaults

## Description

Sets the default file system types and the image size based on the current media.

## Parameters

### `discRecorder` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) the identifies the device that contains the current media.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_RECORDER_MEDIA_INCOMPATIBLE** | The media is not compatible or of unknown physical format.<br><br>Value: 0xC0AA0203 |
| **IMAPI_E_IMAGE_TOO_BIG** | Value specified for FreeMediaBlocks property is too small for estimated image size based on current data. <br><br>Value: 0xC0AAB121 |
| **IMAPI_E_NO_SUPPORTED_FILE_SYSTEM** | The specified disc does not contain one of the supported file systems.<br><br>Value: 0xC0AAB151 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)