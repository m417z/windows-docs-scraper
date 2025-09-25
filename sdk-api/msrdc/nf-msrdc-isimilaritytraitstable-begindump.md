# ISimilarityTraitsTable::BeginDump

## Description

Retrieves similarity data from the similarity traits table.

## Parameters

### `similarityTableDumpState` [out, optional]

An optional pointer to a location that will receive the returned [ISimilarityTableDumpState](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytabledumpstate) interface pointer. The caller must release this interface when it is no longer needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **BeginDump** method is used for debugging and garbage collection. It returns an interface pointer to an iterator object that allows the application to efficiently dump all of the entries in the similarity traits table.

## See also

[ISimilarityTraitsTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitstable)