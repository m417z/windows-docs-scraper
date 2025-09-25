# IDiscFormat2Erase::get_FullErase

## Description

Determines the quality of the disc erasure.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the erase operation fully erases the disc by overwriting the entire medium at least once.

Is VARIANT_FALSE if the erase operation overwrites the directory tracks, but not the entire disc. This option requires less time to perform than the full erase option.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase)

[IDiscFormat2Erase::EraseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-erasemedia)

[IDiscFormat2Erase::put_FullErase](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-put_fullerase)