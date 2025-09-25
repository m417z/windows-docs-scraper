# IWMPContentPartner::GetStreamingURL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetStreamingURL** method retrieves the streaming URL of a track.

## Parameters

### `st` [in]

A member of the [WMPStreamingType](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmpstreamingtype) enumeration that specifies the type (music, video, or radio) of the media item to be streamed.

### `pStreamContext` [in]

Pointer to a **VARIANT** that contains the ID of the media item to be streamed. The ID is in the **ulVal** member of the **VARIANT**, which has a type of **VT_UI4**.

### `pbstrURL` [out]

Address of a **BSTR** that receives the URL of the track.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)