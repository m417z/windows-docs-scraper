# IMFASFMultiplexer::ProcessSample

## Description

Delivers input samples to the multiplexer.

## Parameters

### `wStreamNumber` [in]

The stream number of the stream to which the sample belongs.

### `pISample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the input sample. The input sample contains the media data to be converted to ASF data packets. When possible, the time stamp of this sample should be accurate.

### `hnsTimestampAdjust` [in]

The adjustment to apply to the time stamp of the sample. This parameter is used if the caller wants to shift the sample time on *pISample*. This value should be positive if the time stamp should be pushed ahead and negative if the time stamp should be pushed back. This time stamp is added to sample time on *pISample*, and the resulting time is used by the multiplexer instead of the original sample time. If no adjustment is needed, set this value to 0.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOTACCEPTING** | There are too many packets waiting to be retrieved from the multiplexer. Call [IMFASFMultiplexer::GetNextPacket](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getnextpacket) to get the packets. |
| **MF_E_BANDWIDTH_OVERRUN** | The sample that was processed violates the bandwidth limitations specified for the stream in the ASF ContentInfo object. When this error is generated, the sample is dropped. |
| **MF_E_INVALIDSTREAMNUMBER** | The value passed in *wStreamNumber* is invalid. |
| **MF_E_LATE_SAMPLE** | The presentation time of the input media sample is earlier than the send time. |

## Remarks

The application passes samples to **ProcessSample**, and the ASF multiplexer queues them internally until they are ready to be placed into ASF packets. Call [IMFASFMultiplexer::GetNextPacket](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getnextpacket) to get the ASF data packet.

After each call to **ProcessSample**, call [GetNextPacket](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getnextpacket) in a loop to get all of the available data packets. For a code example, see [Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets).

## See also

[Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)