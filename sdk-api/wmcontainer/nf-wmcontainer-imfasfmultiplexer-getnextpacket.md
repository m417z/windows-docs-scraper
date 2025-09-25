# IMFASFMultiplexer::GetNextPacket

## Description

Retrieves the next output ASF packet from the multiplexer.

## Parameters

### `pdwStatusFlags` [out]

Receives zero or more status flags. If more than one packet is waiting, the method sets the **ASF_STATUSFLAGS_INCOMPLETE** flag.

### `ppIPacket` [out]

Receives a pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the first output sample of the data packet. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The client needs to call this method, ideally after every call to [IMFASFMultiplexer::ProcessSample](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-processsample), to get the output ASF packets. Call this method in a loop as long as the **ASF_STATUSFLAGS_INCOMPLETE** flag is received.

If no packets are ready, the method returns **S_OK** but does not return a sample in *ppIPacket*.

## See also

[Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)

[IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample)