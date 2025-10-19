# IMFPMediaPlayer::CreateMediaItemFromURL

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Creates a media item from a URL.

## Parameters

### `pwszURL` [in]

Null-terminated string that contains the URL of a media file.

### `fSync` [in]

If **TRUE**, the method blocks until it completes. If **FALSE**, the method does not block and completes asynchronously.

### `dwUserData` [in]

Application-defined value to store in the media item. To retrieve this value from the media item, call [IMFPMediaItem::GetUserData](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getuserdata).

### `ppMediaItem` [out]

Receives a pointer to the [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) interface. The caller must release the interface. If *fSync* is **TRUE**, this parameter must be a valid pointer. If *bSync* is **FALSE**, this parameter must be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDREQUEST** | Invalid request. This error can occur when *fSync* is **FALSE** and the application did not provide a callback interface. See Remarks. |
| **MF_E_SHUTDOWN** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |
| **MF_E_UNSUPPORTED_SCHEME** | Unsupported protocol. |

## Remarks

This method does not queue the media item for playback. To queue the item for playback, call [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem).

The **CreateMediaItemFromURL** method can be called either synchronously or asynchronously:

* If *fSync* is **TRUE**, the method completes synchronously. The [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) pointer is returned in the *ppMediaItem* parameter.
* If *fSync* is **FALSE**, the method completes asynchronously. When the operation completes, the application's [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback method is invoked. The event type is **MFP_EVENT_TYPE_MEDIAITEM_CREATED**. The event data contains the [IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem) pointer for the new media item.

The callback interface is set when you first call [MFPCreateMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfpcreatemediaplayer) to create the MFPlay player object. If you do not provide a callback interface, the *fSync* parameter must be **TRUE**. Otherwise, **CreateMediaItemFromURL** returns **MF_E_INVALIDREQUEST**.

If you make multiple asynchronous calls to **CreateMediaItemFromURL**, they are not guaranteed to complete in the same order. Use the *dwUserData* parameter to match created media items with pending requests.

Currently, this method returns **MF_E_UNSUPPORTED_SCHEME** if the URL specifies any of the following protocols: rtsp*, mms*, or mcast. If you want to use the Media Foundation network source with MFPlay, first use the [Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver) to create the source, and then call [IMFPMediaPlayer::CreateMediaItemFromObject](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromobject).

### Configuring the Source

Internally, this method creates a media source. To configure the media source, do the following:

1. Call **QueryInterface** on the [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) pointer to get the **IPropertyStore** interface.
2. Call **IPropertyStore::SetValue** to set properties for the media source. For a list of configuration properties, see [Configuring a Media Source](https://learn.microsoft.com/windows/desktop/medfound/configuring-a-media-source). Third-party media sources may define custom properties.
3. Call the **CreateMediaItemFromURL** method to create the media item.

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)