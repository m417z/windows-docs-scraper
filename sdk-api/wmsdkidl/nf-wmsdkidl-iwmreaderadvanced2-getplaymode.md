# IWMReaderAdvanced2::GetPlayMode

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetPlayMode** method retrieves the current play mode.

## Parameters

### `pMode` [out]

Pointer to a variable that receives a member of the [WMT_PLAY_MODE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_play_mode) enumeration type.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Before a file is opened, this method returns the play mode the reader will use to open a file. The default setting is auto-select (the reader picks the mode). After a file is opened, this method returns the actual mode used to play the file. For an asynchronous **Open** request, the actual mode can be obtained after receiving the WMT_OPENED status message.

For more information, see the Remarks section of [IWMReaderAdvanced2::SetPlayMode](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-setplaymode).

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)