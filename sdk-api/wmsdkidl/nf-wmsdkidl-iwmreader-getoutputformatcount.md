# IWMReader::GetOutputFormatCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputFormatCount** method is used for determining all possible format types supported by this output media stream on the reader.

## Parameters

### `dwOutputNumber` [in]

**DWORD** containing the output number.

### `pcFormats` [out]

Pointer to a count of formats.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The number of formats that can be delivered on output is determined by the decoding codec. The Windows Media codecs can deliver media samples for a stream in a number of formats. For example, the Windows Media Video 9 codec can deliver samples as bitmapped images or as [YUV](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) images with varying properties to suit your needs.

Every compressed media type has a default output format determined by the codec. You can obtain the properties of the default output format by calling [IWMReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputprops).

This method is synchronous and does not result in any messages being sent to the status callback.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)

[IWMReader::GetOutputFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputformat)