# IMFASFIndexer::SetIndexStatus

## Description

Configures the index for a stream.

## Parameters

### `pbIndexDescriptor` [in]

The index descriptor to set. The index descriptor is an [ASF_INDEX_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_index_descriptor) structure, optionally followed by index-specific data.

### `cbIndexDescriptor` [in]

The size, in bytes, of the index descriptor.

### `fGenerateIndex` [in]

A Boolean value. Set to **TRUE** to have the indexer create an index of the type specified for the stream specified in the index descriptor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | At attempt was made to change the index status in a seek-only scenario. For more information, see Remarks. |

## Remarks

You must make all calls to **SetIndexStatus** before making any calls to [IMFASFIndexer::GenerateIndexEntries](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-generateindexentries).

The indexer object is configured to create temporal indexes for each stream by default. Call this method only if you want to override the default settings.

You cannot use this method in an index reading scenario. You can only use this method when writing indexes.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)