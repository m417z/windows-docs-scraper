# IWMWriter::GetInputCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetInputCount** method retrieves the number of uncompressed input streams.

## Parameters

### `pcInputs` [out]

Pointer to a count of inputs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcInputs* parameter is **NULL**. |

## Remarks

This method along with [GetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputprops) can be used to enumerate through the various inputs, and get the input format of each. These are not the output Windows Media streams specified in the profile; in a multiple bit rate scenario, one input stream can map to multiple Windows Media streams.

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[To Identify Inputs By Number](https://learn.microsoft.com/windows/desktop/wmformat/to-identify-inputs-by-number)