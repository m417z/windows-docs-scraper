# ISimilarityFileIdTable::Append

## Description

Adds the file ID to the similarity file ID table.

## Parameters

### `similarityFileId` [in]

The file ID to be added to the similarity file ID table.

### `similarityFileIndex` [out]

A pointer to a variable that receives the file index for the file ID's entry in the similarity file ID table.

## Return value

Returns **S_OK** on success, or an error **HRESULT** on failure.

This method can also return the following error codes.

## Remarks

If the **Append** method fails, the similarity file ID table is marked as corrupted and must be rebuilt.

## See also

[ISimilarityFileIdTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityfileidtable)