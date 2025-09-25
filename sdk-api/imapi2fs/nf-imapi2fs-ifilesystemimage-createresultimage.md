# IFileSystemImage::CreateResultImage

## Description

Create the result object that contains the file system and file data.

## Parameters

### `resultStream` [out]

An [IFileSystemImageResult](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult) interface of the image result.

Client applications can stream the image to media or other long-term storage devices, such as disk drives.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

 Currently, **IFileSystemImage::CreateResultImage** will require disc media access as a result of a previous [IFileSystemImage::IdentifyFileSystemsOnDisc](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-identifyfilesystemsondisc) method call. To resolve this issue, it is recommended that another [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) object be created specifically for the **IFileSystemImage::IdentifyFileSystemsOnDisc** operation.

The resulting stream can be saved as an ISO file if the file system is generated in a single session and has a start address of zero.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_filesystemstocreate)

[IFileSystemImage::put_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_filesystemstocreate)

[IFilesystemImage::ChooseImageDefaults](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaults)

[IFilesystemImage::ChooseImageDefaultsForMediaType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaultsformediatype)