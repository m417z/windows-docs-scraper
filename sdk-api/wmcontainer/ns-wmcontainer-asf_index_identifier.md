# ASF_INDEX_IDENTIFIER structure

## Description

Specifies an index for the ASF indexer object.

## Members

### `guidIndexType`

The type of index. Currently this value must be GUID_NULL, which specifies time-based indexing.

### `wStreamNumber`

The stream number to which this structure applies.

## Remarks

The index object of an ASF file can contain a number of distinct indexes. Each index is identified by the type of index and the stream number. No ASF index object can contain more than one index for a particular combination of stream number and index type.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer::GetIndexStatus](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getindexstatus)

[IMFASFIndexer::SetIndexStatus](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-setindexstatus)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)