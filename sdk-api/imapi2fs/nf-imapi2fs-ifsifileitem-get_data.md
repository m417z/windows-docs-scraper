# IFsiFileItem::get_Data

## Description

Retrieves the data stream of the file's content.

## Parameters

### `pVal` [out]

An **IStream** interface of the contents of the file.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

The contents of the file becomes read-only once the file item is added to file system image.

## See also

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)

[IFsiFileItem::put_Data](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-put_data)