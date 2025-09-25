# ISimilarityFileIdTable::CloseTable

## Description

Closes a similarity file ID table.

## Parameters

### `isValid`

**FALSE** if the similarity file ID table should be deleted when it is closed; otherwise, **TRUE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If **FALSE** is specified for the *isValid* parameter, only the table is deleted; the similarity file is not deleted. The caller is responsible for deleting the similarity file.

When the **CloseTable** method returns, the table is always closed, even if this method returns an error code.

## See also

[ISimilarityFileIdTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityfileidtable)