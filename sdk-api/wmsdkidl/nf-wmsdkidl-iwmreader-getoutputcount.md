# IWMReader::GetOutputCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputCount** method retrieves the number of uncompressed media streams that will be delivered for the file loaded in the reader.

## Parameters

### `pcOutputs` [out]

Pointer to a count of outputs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pcOutputs* parameter is **NULL**. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

A file with mutually exclusive streams contains several streams that are delivered to the same output. But only one of those streams can be delivered at a time during playback. When reading a file, you can identify its outputs by looping through the outputs and getting the media properties of each by calling [IWMReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputprops).

This method is synchronous and does not result in any messages being sent to the status callback.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)

[IWMReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputprops)