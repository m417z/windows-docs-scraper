# IDiscFormat2Data::put_PostgapAlreadyInImage

## Description

Determines if the data stream contains post-writing gaps.

## Parameters

### `value` [in]

Set to VARIANT_TRUE if the data stream contains post-writing gaps; otherwise, VARIANT_FALSE. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |

## Remarks

Note that writing to CD-R/RW media will automatically append a post-gap of 150 sectors, unless this property is explicitly disabled.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::get_PostgapAlreadyInImage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_postgapalreadyinimage)