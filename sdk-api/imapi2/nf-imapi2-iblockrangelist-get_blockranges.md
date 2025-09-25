# IBlockRangeList::get_BlockRanges

## Description

Returns the list of sector ranges in the form of a safe array of variants of type VT_Dispatch.

## Parameters

### `value` [out, retval]

List of sector ranges. Each element of the list is a VARIANT of type VT_Dispatch. Query the pdispVal member of the variant for the [IBlockRange](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrange) interface.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

The order of sector ranges in [IBlockRangeList](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrangelist) is taken into account during burning. The sector ranges having lower indexes in the safe array returned by **IBlockRangeList::get_BlockRanges** are written before those with higher indexes.

## See also

[IBlockRangeList](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrangelist)