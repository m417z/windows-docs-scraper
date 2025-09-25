# IFsiItem::put_CreationTime

## Description

Sets the date and time that the directory or file item was created and added to the file system image.

## Parameters

### `newVal` [in]

Date and time that the directory or file item was created and added to the file system image, according to UTC time. Defaults to the time the item was added to the image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

IMAPI does not support the extended attribute for *CreationTime*, and as a result, UDFS populates the *CreationTime* with the value expressed by the *LastAccessed* property from the file entry.

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::get_CreationTime](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_creationtime)