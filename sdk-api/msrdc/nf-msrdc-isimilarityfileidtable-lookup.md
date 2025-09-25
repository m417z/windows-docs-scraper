# ISimilarityFileIdTable::Lookup

## Description

Retrieves the file ID that corresponds to a given file index in the similarity file ID table.

## Parameters

### `similarityFileIndex` [in]

The file index that was previously returned for the file ID by the [ISimilarityFileIdTable::Append](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarityfileidtable-append) method.

### `similarityFileId` [out]

A pointer to a variable that receives the file ID. If the file has been marked as not valid, the file ID receives zero.

## Return value

Returns **S_OK** on success, or an error **HRESULT** on failure.

This method can also return the following error code.

## See also

[ISimilarityFileIdTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityfileidtable)