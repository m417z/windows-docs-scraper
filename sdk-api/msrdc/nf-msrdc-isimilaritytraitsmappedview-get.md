# ISimilarityTraitsMappedView::Get

## Description

Returns information about the mapped view of a similarity traits table file.

## Parameters

### `index` [in]

Beginning file offset, in bytes, of the underlying file data to be mapped in the mapped view.

### `dirty` [in]

If **TRUE** is specified, the data in the currently mapped view has been changed; otherwise, the data has not changed. This parameter can be used to determine if data may need to be written to disk.

### `numElements` [in]

Minimum number of bytes of data to be mapped in the mapped view.

### `viewInfo` [out]

Pointer to a location that receives a [SimilarityMappedViewInfo](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritymappedviewinfo) structure containing information about the mapped view.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

At least *numElements* bytes must be available in the mapped view, but depending on the application, more bytes may actually be mapped. The data must be 8-byte aligned relative to the file offset. For example, the data at file offset 0x8001 must be mapped to some memory location whose address modulo 8 is 1.

## See also

[ISimilarityTraitsMappedView](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmappedview)