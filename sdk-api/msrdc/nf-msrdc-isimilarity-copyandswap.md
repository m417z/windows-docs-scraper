# ISimilarity::CopyAndSwap

## Description

 Creates copies of an existing similarity traits table and an existing similarity file ID table, swaps the internal pointers, and deletes the existing tables.

After the **CopyAndSwap** method returns, the application continues to use the same [ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity) object that it used before calling this method. However, the **ISimilarity** object is now associated with a different similarity file on disk.

## Parameters

### `newSimilarityTables` [in, optional]

An optional pointer to a temporary [ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity) object that is used to create temporary copies of the tables. Before calling the **CopyAndSwap** method, the caller must call the [CreateTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-createtable) method to create the temporary tables. On return, the caller must call the [CloseTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarity-closetable) method to close the temporary tables.

### `reportProgress` [in, optional]

An optional pointer to an [ISimilarityReportProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityreportprogress) object that will receive information on the progress of the copy-and-swap operation and allow the application to stop the copy operation. The caller must release this interface when it is no longer needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity)

[ISimilarityReportProgress::ReportProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarityreportprogress-reportprogress)