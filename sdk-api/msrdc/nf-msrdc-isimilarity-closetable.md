# ISimilarity::CloseTable

## Description

Closes the tables in a similarity file.

## Parameters

### `isValid` [in]

**FALSE** if the similarity traits table and similarity file ID table should be deleted when they are closed; otherwise, **TRUE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If **FALSE** is specified for the *isValid* parameter, only the tables are deleted; the similarity file is not deleted. The caller is responsible for deleting the similarity file.

When the **CloseTable** method returns, the tables are always closed, even if this method returns an error code.

## See also

[ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity)