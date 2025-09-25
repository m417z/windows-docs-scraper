# IDiscFormat2Data::get_PostgapAlreadyInImage

## Description

Determines if the data stream contains post-writing gaps.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the data stream contains post-writing gaps; otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::put_PostgapAlreadyInImage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_postgapalreadyinimage)