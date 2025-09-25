# IBootOptions::get_BootImage

## Description

Retrieves a pointer to the boot image data stream.

## Parameters

### `pVal` [out]

Pointer to the **IStream** interface associated with the boot image data stream.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::AssignBootImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-assignbootimage)

[IFileSystemImage::get_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_bootimageoptions)

[IFileSystemImage::put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions)