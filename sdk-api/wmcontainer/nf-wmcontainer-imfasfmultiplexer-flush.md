# IMFASFMultiplexer::Flush

## Description

Signals the multiplexer to process all queued output media samples. Call this method after passing the last sample to the multiplexer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You must call **Flush** after the last sample has been passed into the ASF multiplexer and before you call [IMFASFMultiplexer::End](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-end). This causes all output media samples in progress to be completed. After calling **Flush**, call [IMFASFMultiplexer::GetNextPacket](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getnextpacket) in a loop until all the pending media samples have been packetized.

## See also

[Generating New ASF Data Packets](https://learn.microsoft.com/windows/desktop/medfound/generating-new-asf-data-packets)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)