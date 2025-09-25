# IFindSimilarResults::GetSize

## Description

Retrieves the number of entries in the file list that was returned by the [ISimilarity::FindSimilarFileId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-findsimilarfileid) method.

The actual number of similarity file IDs that are returned by the [GetNextFileId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-ifindsimilarresults-getnextfileid) method may be less than the number that is returned by the **GetSize** method. **GetNextFileId** returns only valid similarity file IDs. However, **GetSize** counts all entries, even if their similarity file IDs are not valid.

## Parameters

### `size` [out]

A pointer to a variable that receives the number of entries in the file list.

## Return value

This method always returns **S_OK**.

## See also

[IFindSimilarResults](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-ifindsimilarresults)