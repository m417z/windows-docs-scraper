# ISimilarity::FindSimilarFileId

## Description

Returns a list of files that are similar to a given file.

## Parameters

### `similarityData` [in]

A pointer to a [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure that contains similarity information for the file.

### `numberOfMatchesRequired`

TBD

### `resultsSize` [in]

The number of file IDs that can be stored in the [IFindSimilarResults](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-ifindsimilarresults) object that the *findSimilarResults* parameter points to.

### `findSimilarResults` [out, optional]

A pointer to a location that will receive the returned [IFindSimilarResults](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-ifindsimilarresults) interface pointer. The caller must release this interface when it is no longer needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The file IDs that are returned in the *findSimilarResults* parameter may include IDs of files that have been deleted.

## See also

[ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity)