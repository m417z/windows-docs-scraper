# FindSimilarFileIndexResults structure

## Description

Contains the file index information that the [ISimilarityTraitsTable::FindSimilarFileIndex](https://learn.microsoft.com/windows/desktop/api/msrdc/nf-msrdc-isimilaritytraitstable-findsimilarfileindex) method returned for a matching file.

## Members

### `m_FileIndex`

The index of the matching file in the similarity traits table.

### `m_MatchCount`

The number of traits that were matched. The valid range is from **MSRDC_MINIMUM_MATCHESREQUIRED** to
**MSRDC_MAXIMUM_MATCHESREQUIRED**.

## See also

[ISimilarityTraitsTable::FindSimilarFileIndex](https://learn.microsoft.com/windows/desktop/api/msrdc/nf-msrdc-isimilaritytraitstable-findsimilarfileindex)