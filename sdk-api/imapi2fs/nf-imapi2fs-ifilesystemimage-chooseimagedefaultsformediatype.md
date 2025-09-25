# IFileSystemImage::ChooseImageDefaultsForMediaType

## Description

Sets the default file system types and the image size based on the specified media type.

## Parameters

### `value` [in]

Identifies the physical media type that will receive the burn image. For possible values, see the [IMAPI_MEDIA_PHYSICAL_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_media_physical_type) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_IMAGE_TOO_BIG** | Value specified for FreeMediaBlocks property is too small for estimated image size based on current data. <br><br>Value: 0xC0AAB121 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)