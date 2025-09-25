# ISimilarityFileIdTable::Invalidate

## Description

Marks a file ID as not valid in the similarity file ID table.

This method should be called for files that have been deleted or are otherwise no longer available.

## Parameters

### `similarityFileIndex` [in]

The index of the file ID's entry in the similarity file ID table.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The file ID is marked as not valid by setting the contents of the corresponding [SimilarityFileId](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similarityfileid) structure to all zeros. A file ID that is marked as not valid will not be included in the results that are returned by the [ISimilarity::FindSimilarFileId](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-findsimilarfileid) method.

## See also

[ISimilarityFileIdTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityfileidtable)