# IWMSyncReader::GetOutputCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputCount** method retrieves the number of outputs that exist for the file open in the synchronous reader.

## Parameters

### `pcOutputs` [out]

Pointer to a **DWORD** that receives the number of outputs in the file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pcOutputs* parameter is **NULL**. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

To enumerate the outputs, call **GetOutputCount** to get the number of outputs, and then call **GetOutputProps**.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getoutputprops)

[Inputs, Streams and Outputs](https://learn.microsoft.com/windows/desktop/wmformat/inputs-streams-and-outputs)