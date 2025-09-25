# IWMVideoMediaProps::SetQuality

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetQuality** method specifies the quality setting for the video stream.

## Parameters

### `dwQuality` [in]

**DWORD** specifying the quality setting, in the range from zero (maximum [frame rate](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary)) to 100 (maximum image quality).

## Return value

This method always returns S_OK.

## See also

[IWMVideoMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmvideomediaprops)

[IWMVideoMediaProps::GetQuality](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmvideomediaprops-getquality)