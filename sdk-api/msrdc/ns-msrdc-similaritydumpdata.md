# SimilarityDumpData structure

## Description

Contains the similarity information that was returned for a file by the [ISimilarityTableDumpState::GetNextData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilaritytabledumpstate-getnextdata) method.

## Members

### `m_FileIndex`

The index of the [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure in the similarity traits table.

### `m_Data`

A [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure that contains the similarity data for the file.

## See also

[ISimilarityTableDumpState](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytabledumpstate)