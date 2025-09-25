# IDiscFormat2Erase::put_FullErase

## Description

Determines the quality of the disc erasure.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to fully erase the disc by overwriting the entire medium at least once.

Set to VARIANT_FALSE to overwrite the directory tracks, but not the entire disc. This option requires less time to perform than the full erase option.

The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase)

[IDiscFormat2Erase::EraseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-erasemedia)

[IDiscFormat2Erase::get_FullErase](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-get_fullerase)