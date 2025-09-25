# ISimilarityTraitsTable::FindSimilarFileIndex

## Description

Returns a list of files that are similar to a given file. The results in the list are sorted in order of similarity, beginning with the most similar file.

## Parameters

### `similarityData` [in]

A pointer to a [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure that contains similarity information for the file.

### `numberOfMatchesRequired`

TBD

### `findSimilarFileIndexResults` [out]

A pointer to a buffer that receives an array of [FindSimilarFileIndexResults](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-findsimilarfileindexresults) structures that contain the requested information.

### `resultsSize` [in]

The number of [FindSimilarFileIndexResults](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-findsimilarfileindexresults) structures that can be stored in the buffer that the *findSimilarFileIndexResults* parameter points to.

### `resultsUsed` [out]

The number of [FindSimilarFileIndexResults](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-findsimilarfileindexresults) structures that were returned in the buffer that the *findSimilarFileIndexResults* parameter points to.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The list of files that is returned in the *findSimilarFileIndexResults* parameter may include files that have been deleted.

## See also

[ISimilarityTraitsTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitstable)