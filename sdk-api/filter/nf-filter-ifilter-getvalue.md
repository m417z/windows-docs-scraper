# IFilter::GetValue

## Description

Retrieves a value (internal value-type property) from a chunk, which must have a [CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate) enumeration value of CHUNK_VALUE.

## Parameters

### `ppPropValue` [out]

A pointer to an output variable that receives a pointer to the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the value-type property.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **FILTER_E_NO_MORE_VALUES** | The [GetValue](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getvalue) method has already been called on this chunk; this value should be returned until the [IFilter::GetChunk](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getchunk) method has been called successfully and has advanced to the next chunk. |
| **FILTER_E_NO_VALUES** | The current chunk does not have a [CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate) enumeration value of CHUNK_VALUE. |

## Remarks

Call the **GetValue** method only once per chunk.

Note that the effect of producing the same value from more than one chunk is undefined. Only the last setting of the value is valid.

### Notes to Callers

Allocate the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Some **PROPVARIANT** structures contain pointers, which can be freed by calling the [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear) function. It is up to the caller of the **GetValue** method to call **PropVariantClear**.

## See also

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)