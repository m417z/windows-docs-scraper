# IWMReader::GetOutputProps

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputProps** method retrieves the current properties of an uncompressed output stream.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `ppOutput` [out]

Pointer to a pointer to an [IWMOutputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops) interface. This interface belongs to an output media properties object created by a successful call to this method. Any changes made to the output media properties object will have no effect on the output of the reader unless you pass this interface in a call to [IWMReader::SetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-setoutputprops).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppOutput* parameter is **NULL**, or the *dwOutputNum* parameter is greater than the number of outputs. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

The Windows Media codecs can deliver media samples for a stream in a number of formats. For example, the Windows Media Video 9 codec can deliver samples as bitmapped images or as [YUV](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) images with varying properties to suit your needs. When you load a file the output properties are set to the default for compressed media type in the stream associated with the output. You can examine the possible output formats by calling [IWMReader::GetOutputFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputformatcount) to get the total number of possible formats and then calling [IWMReader::GetOutputFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputformat) for each.

This method is synchronous and does not result in any messages being sent to the status callback.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)