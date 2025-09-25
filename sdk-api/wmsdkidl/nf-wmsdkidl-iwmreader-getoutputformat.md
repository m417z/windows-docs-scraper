# IWMReader::GetOutputFormat

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputFormat** method retrieves the supported formats for a specified output media stream.

## Parameters

### `dwOutputNumber` [in]

**DWORD** containing the output number.

### `dwFormatNumber` [in]

**DWORD** containing the format number.

### `ppProps` [out]

Pointer to a pointer to an [IWMOutputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops) interface. This interface belongs to an output media properties object created by a successful call to this method. The properties exposed by this interface represent formats than can be supported by the specified output; the current properties set for the output can be obtained by calling [IWMReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputprops).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The Windows Media codecs can deliver media samples for a stream in a number of formats. For example, the Windows Media Video 9 codec can deliver samples in various RGB or [YUV](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) formats. You can use this method in conjunction with [IWMReader::GetOutputFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-getoutputformatcount) to loop through the available formats and find the one you need.

To use a format returned by this method, you must call [IWMReader::SetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-setoutputprops).

This method is synchronous and does not result in any messages being sent to the status callback.

## See also

[IWMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader)