# ISimilarityTraitsTable::Append

## Description

Adds a [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure to the similarity traits table.

## Parameters

### `data` [in]

The [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure to be added to the similarity traits table.

### `fileIndex` [in]

The index in the similarity traits table where the [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure is to be inserted.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The application must supply *fileIndex* values that are greater than zero and are always increasing. Otherwise, this method returns the **E_INVALIDARG** error code.

## See also

[ISimilarityTraitsTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitstable)