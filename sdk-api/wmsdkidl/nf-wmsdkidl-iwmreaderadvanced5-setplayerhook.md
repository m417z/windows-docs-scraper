# IWMReaderAdvanced5::SetPlayerHook

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetPlayerHook** method assigns a player-hook callback to the reader. The reader calls the callback method before sending each sample to the graphics processor for decompression.

## Parameters

### `dwOutputNum` [in]

The output number to which the player-hook callback applies.

### `pHook` [in]

Pointer to the implementation of the [IWMPlayerHook](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmplayerhook) interface that will be used in association with the specified output.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

DirectX Video Acceleration enables supported graphics cards to decompress video samples.

## See also

[IWMReaderAdvanced5 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced5)