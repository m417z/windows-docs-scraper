# IFileSystemImage::CreateFileItem

## Description

Create a file item with the specified name.

## Parameters

### `name` [in]

String that contains the name of the file item to create.

### `newItem` [out]

An [IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem) interface of the new file item. When done, call the **IFsiFileItem::Release** method to release the interface.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The provided *name* is not valid.<br><br>Value: 0xC0AAB101 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

After setting properties on the [IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem) interface, call the [IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add) method on the parent directory item to add it to the file system image.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)