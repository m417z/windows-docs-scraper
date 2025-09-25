# IWMReaderTypeNegotiation::TryOutputProps

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **TryOutputProps** method ascertains whether certain changes to the properties of an output are possible.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pOutput` [in]

Pointer to the [IWMOutputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops) interface of an output media properties object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwOutputNumber* is too large. |
| **E_UNEXPECTED** | Unspecified error. |
| **NS_E_INVALID_OUTPUT_FORMAT** | Media type of object is not valid. |
| **E_OUTOFMEMORY** | Not enough memory to complete the task. |

## Remarks

This method is usually used to test different output properties to find out if they are possible; for example, to find out whether a video stream can be rendered at a resolution of 320 x 240 pixels in 16-bit color. To perform this testing, call [IWMReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputprops) to retrieve an **IWMOutputMediaProps** interface, and alter properties by using that interface. Then test the modified object with the **TryOutputProps** method. If it returns S_OK, the new properties would work.

## See also

[IWMOutputMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops)

[IWMReaderTypeNegotiation Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadertypenegotiation)

[Inputs, Streams and Outputs](https://learn.microsoft.com/windows/desktop/wmformat/inputs-streams-and-outputs)