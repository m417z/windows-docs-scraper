# IMFASFIndexer::GetSeekPositionForValue

## Description

Given a desired seek time, gets the offset from which the client should start reading data.

## Parameters

### `pvarValue` [in]

The value of the index entry for which to get the position. The format of this value varies depending on the type of index, which is specified in the index identifier. For time-based indexing, the variant type is **VT_I8** and the value is the desired seek time, in 100-nanosecond units.

### `pIndexIdentifier` [in]

Pointer to an [ASF_INDEX_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ns-wmcontainer-asf_index_identifier) structure that identifies the stream number and index type.

### `pcbOffsetWithinData` [out]

Receives the offset within the data segment of the ASF Data Object. The offset is in bytes, and is relative to the start of packet 0. The offset gives the starting location from which the client should begin reading from the stream. This location might not correspond exactly to the requested seek time.

For reverse playback, if no key frame exists after the desired seek position, this parameter receives the value **MFASFINDEXER_READ_FOR_REVERSEPLAYBACK_OUTOFDATASEGMENT**. In that case, the seek position should be 1 byte pass the end of the data segment.

### `phnsApproxTime` [out]

Receives the approximate time stamp of the data that is located at the offset returned in the *pcbOffsetWithinData* parameter. The accuracy of this value is equal to the indexing interval of the ASF index, typically about 1 second.

* If the index type specified in *pIndexIdentifier* is **GUID_NULL** (time indexing), this parameter can be **NULL**.
* For all other index types, this parameter must be **NULL**.

If the approximate time stamp cannot be determined, this parameter receives the value **MFASFINDEXER_APPROX_SEEK_TIME_UNKNOWN**.

### `pdwPayloadNumberOfStreamWithinPacket` [out]

Receives the payload number of the payload that contains the information for the specified stream. Packets can contain multiple payloads, each containing data for a different stream. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ASF_OUTOFRANGE** | The requested seek time is out of range. |
| **MF_E_NO_INDEX** | No index exists of the specified type for the specified stream. |

## See also

[ASF Index Object](https://learn.microsoft.com/windows/desktop/medfound/asf-index-object)

[IMFASFIndexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfindexer)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)