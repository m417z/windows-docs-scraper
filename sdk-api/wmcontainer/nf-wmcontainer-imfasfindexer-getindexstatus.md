# IMFASFIndexer::GetIndexStatus

## Description

Retrieves the index settings for a specified stream and index type.

## Parameters

### `pIndexIdentifier` [in]

Pointer to an [ASF_INDEX_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_index_identifier) structure that contains the stream number and index type for which to get the status.

### `pfIsIndexed` [out]

A variable that retrieves a Boolean value specifying whether the index described by *pIndexIdentifier* has been created.

### `pbIndexDescriptor` [out]

A buffer that receives the index descriptor. The index descriptor consists of an [ASF_INDEX_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_index_descriptor) structure, optionally followed by index-specific data.

### `pcbIndexDescriptor` [in, out]

On input, specifies the size, in bytes, of the buffer that *pbIndexDescriptor* points to. The value can be zero if *pbIndexDescriptor* is **NULL**. On output, receives the size of the index descriptor, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The buffer size specified in *pcbIndexDescriptor* is too small. |

## Remarks

To read an existing ASF index, call [IMFASFIndexer::SetIndexByteStreams](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfindexer-setindexbytestreams) before calling this method.

If an index exists for the stream and the value passed into *pcbIndexDescriptor* is smaller than the required size of the *pbIndexDescriptor* buffer, the method returns MF_E_BUFFERTOOSMALL. The required buffer size is returned in the *pcbIndexDescriptor* parameter.

If there is no index for the specified stream, the method returns **FALSE** in the *pfIsIndexed* parameter.

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)