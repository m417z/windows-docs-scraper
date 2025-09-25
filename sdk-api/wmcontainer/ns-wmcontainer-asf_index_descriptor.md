# ASF_INDEX_DESCRIPTOR structure

## Description

Describes the indexing configuration for a stream and type of index.

## Members

### `Identifier`

[ASF_INDEX_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_index_identifier) structure that identifies the stream number and the type of index.

### `cPerEntryBytes`

Number of bytes used for each index entry. If the value is MFASFINDEXER_PER_ENTRY_BYTES_DYNAMIC, the index entries have variable size.

### `szDescription`

Optional text description of the index.

### `dwInterval`

Indexing interval. The units of this value depend on the index type. A value of MFASFINDEXER_NO_FIXED_INTERVAL indicates that there is no fixed indexing interval.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer::GetIndexStatus](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-getindexstatus)

[IMFASFIndexer::SetIndexStatus](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-setindexstatus)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)