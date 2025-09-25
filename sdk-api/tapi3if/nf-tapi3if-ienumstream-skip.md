# IEnumStream::Skip

## Description

The
**Skip** method skips over the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements to skip.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Number of elements skipped was *celt*. |
| **S_FALSE** | Number of elements skipped was not *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[IEnumStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumstream)

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)