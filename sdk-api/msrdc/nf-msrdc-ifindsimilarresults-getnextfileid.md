# IFindSimilarResults::GetNextFileId

## Description

Retrieves the next valid similarity file ID in the file list that was returned by the [ISimilarity::FindSimilarFileId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-findsimilarfileid) method.

## Parameters

### `numTraitsMatched` [out]

A pointer to a variable that receives the number of traits that were matched.

### `similarityFileId` [out]

A pointer to a [SimilarityFileId](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similarityfileid) structure that contains the similarity file ID of the matching file.

## Return value

Returns **S_OK** on success, or an error **HRESULT** on failure.

This method can also return the following error code.

## See also

[IFindSimilarResults](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-ifindsimilarresults)