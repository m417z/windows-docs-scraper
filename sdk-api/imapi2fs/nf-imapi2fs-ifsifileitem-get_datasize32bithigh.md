# IFsiFileItem::get_DataSize32BitHigh

## Description

Retrieves the most significant 32 bits of the [IFsiFileItem::get_DataSize](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize) property.

## Parameters

### `pVal` [out]

Most significant 32 bits of the [IFsiFileItem::get_DataSize](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize) property.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This property and [IFsiFileItem::get_DataSize32BitLow](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize32bitlow) together provide the size of the file as two 32-bit numbers for languages that do not support 64-bit values, such as VBScript and Visual Basic 6.

## See also

[IFsiFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem)

[IFsiFileItem::get_DataSize](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsifileitem-get_datasize)