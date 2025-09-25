# IBlockRange::get_EndLba

## Description

Retrieves the end sector of the range specified by the [IBlockRange](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrange) interface.

## Parameters

### `value` [out]

The end sector of the range.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Invalid pointer. |

## Remarks

The sector number returned by this method is included in the range.

## See also

[IBlockRange](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrange)