# IFsiFileItem::get_DataSize

## Description

Retrieves the number of bytes in the file.

## Parameters

### `pVal` [out]

Size, in bytes, of the file.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)

[IFsiFileItem::get_DataSize32BitHigh](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize32bithigh)

[IFsiFileItem::get_DataSize32BitLow](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize32bitlow)