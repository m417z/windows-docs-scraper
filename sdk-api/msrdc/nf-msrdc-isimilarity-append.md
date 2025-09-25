# ISimilarity::Append

## Description

Adds the file ID and similarity data information to the tables in the similarity file.

## Parameters

### `similarityFileId` [in]

A pointer to the [SimilarityFileId](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similarityfileid) structure to be added to the similarity file ID table.

### `similarityData` [in]

A pointer to the [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure to be added to the similarity traits table.

## Return value

Returns **S_OK** on success, or an error **HRESULT** on failure.

This method can also return the following error codes.

## Remarks

If this method fails, the similarity file ID table and the similarity traits table are marked as corrupted and must be rebuilt by the application. The application must close the corrupted tables and create new tables.

## See also

[ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity)