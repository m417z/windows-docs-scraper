# IWMCodecAMVideoAccelerator::NegotiateConnection

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **NegotiateConnection** method is called by the output pin on the player's source filter during the connection process when it has been given a DirectX VA media type.

## Parameters

### `pMediaType` [in]

Pointer to the media type structure that represents the media type being proposed for the connection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DMO_E_TYPE_NOT_SET** | No input type has been set on the decoder. |
| **E_FAIL** | The decoder has no valid **IAMVideoAccelerator** interface pointer. |
| **E_POINTER** | *pMediaType* is **NULL**. |

## See also

[Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration)

[IWMCodecAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/wmdxva/nn-wmdxva-iwmcodecamvideoaccelerator)