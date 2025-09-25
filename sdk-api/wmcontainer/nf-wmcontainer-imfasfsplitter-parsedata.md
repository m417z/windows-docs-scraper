# IMFASFSplitter::ParseData

## Description

Sends packetized Advanced Systems Format (ASF) data to the ASF splitter for processing.

## Parameters

### `pIBuffer` [in]

Pointer to the [IMFMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediabuffer) interface of a buffer object containing data to be parsed.

### `cbBufferOffset` [in]

The offset into the data buffer where the splitter should begin parsing. This value is typically set to 0.

### `cbLength` [in]

The length, in bytes, of the data to parse. This value is measured from the offset specified by *cbBufferOffset*. Set to 0 to process to the end of the buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pIBuffer* parameter is **NULL**.<br><br>The specified offset value in *cbBufferOffset* is greater than the length of the buffer.<br><br>The total value of *cbBufferOffset* and *cbLength* is greater than the length of the buffer. |
| **MF_E_NOT_INITIALIZED** | The [IMFASFSplitter::Initialize](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-initialize) method was not called or the call failed. |
| **MF_E_NOTACCEPTING** | The splitter cannot process more input at this time. |

## Remarks

After using this method to parse data, you must call [IMFASFSplitter::GetNextSample](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getnextsample) to retrieve parsed media samples.

If your ASF data contains variable-sized packets, you must set the [MFASFSPLITTER_PACKET_BOUNDARY](https://learn.microsoft.com/windows/desktop/medfound/mfasfsplitter-packet-boundary-attribute) attribute on the buffers to indicate the sample boundaries, and the buffers cannot span multiple packets.

If the method returns ME_E_NOTACCEPTING, call [GetNextSample](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getnextsample) to get the output samples, or call [IMFASFSplitter::Flush](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-flush) to clear the splitter.

The splitter might hold a reference count on the input buffer. Therefore, do not write over the valid data in the buffer after calling this method.

## See also

[ASF Splitter](https://learn.microsoft.com/windows/desktop/medfound/asf-splitter)

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)