# IBlockRange::get_StartLba

## Description

Retrieves the start sector of the range described by [IBlockRange](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrange).

## Parameters

### `value` [out]

The start sector of the range.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Invalid pointer. |

## See also

[IBlockRange](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrange)