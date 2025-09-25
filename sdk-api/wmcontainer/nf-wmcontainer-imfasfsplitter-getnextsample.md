# IMFASFSplitter::GetNextSample

## Description

Retrieves a sample from the Advanced Systems Format (ASF) splitter after the data has been parsed.

## Parameters

### `pdwStatusFlags` [out]

Receives one of the following values.

| Value | Meaning |
| --- | --- |
| **ASF_STATUSFLAGS_INCOMPLETE** | More samples are ready to be retrieved. Call **GetNextSample** in a loop until the *pdwStatusFlags* parameter receives the value zero. |
| **Zero** | No additional samples are ready. Call [IMFASFSplitter::ParseData](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-parsedata) to give more input data to the splitter. |

### `pwStreamNumber` [out]

If the method returns a sample in the *ppISample* parameter, this parameter receives the number of the stream to which the sample belongs.

### `ppISample` [out]

Receives a pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the parsed sample. The caller must release the interface. If no samples are ready, this parameter receives the value **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ASF_INVALIDDATA** | The ASF data in the buffer is invalid. |
| **MF_E_ASF_MISSINGDATA** | There is a gap in the ASF data. |

## Remarks

Before calling this method, call [IMFASFSplitter::ParseData](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-parsedata) to give input data to the splitter. If the input does not contain enough data for a complete sample, the **GetNextSample** method succeeds but returns **NULL** in the *ppISample* parameter.

The ASF splitter skips samples for unselected streams. To select streams, call [IMFASFSplitter::SelectStreams](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-selectstreams).

## See also

[ASF Splitter](https://learn.microsoft.com/windows/desktop/medfound/asf-splitter)

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)