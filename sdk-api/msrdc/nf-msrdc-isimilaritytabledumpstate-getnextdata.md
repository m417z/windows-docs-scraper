# ISimilarityTableDumpState::GetNextData

## Description

Retrieves one or more [SimilarityDumpData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydumpdata) structures from the similarity traits list that was returned by the [ISimilarityTraitsTable::BeginDump](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilaritytraitstable-begindump) method.

## Parameters

### `resultsSize` [in]

The number of [SimilarityDumpData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydumpdata) structures that can be stored in the buffer that the *results* parameter points to.

### `resultsUsed` [out]

A pointer to a variable that receives the number of [SimilarityDumpData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydumpdata) structures that were returned in the buffer that the *results* parameter points to.

### `eof` [out]

A pointer to a variable that receives **TRUE** if the end of the file is reached; otherwise, **FALSE**.

### `results` [in, out]

A pointer to a buffer that receives the [SimilarityDumpData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydumpdata) structures.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISimilarityTableDumpState](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytabledumpstate)