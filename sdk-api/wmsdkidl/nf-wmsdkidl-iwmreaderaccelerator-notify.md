# IWMReaderAccelerator::Notify

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Notify** method is called by the source filter to pass in the negotiated media type.

## Parameters

### `dwOutputNum` [in]

**DWORD** that specifies the stream associated with the notification.

### `pSubtype` [in]

Pointer to a media type that describes the current connection parameters for the stream.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code .

## Remarks

This method enables the reader to update its internal variables and commit to the DirectX VA connection. This is the last place the decoder or reader can fail.

## See also

[Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration)

[IWMReaderAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderaccelerator)