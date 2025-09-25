# IDDrawExclModeVideoCallback::OnUpdateOverlay

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnUpdateOverlay` method informs the application when the overlay surface for the video is about to become visible, invisible, change size, or change position, so that the application can repaint its window appropriately.

## Parameters

### `bBefore` [in]

Boolean value specifying whether the call is being made before or after the overlay-related change. **TRUE** specifies before, **FALSE** specifies after.

### `dwFlags` [in]

Value from the [AM_OVERLAY_NOTIFY_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_am_overlay_notify_flags) enumeration that specifies what is about to change or what changed.

### `bOldVisible` [in]

Boolean value specifying whether the old window is visible. **TRUE** means the old window is visible.

### `prcOldSrc` [in]

Pointer to the rectangle representing the old source position of the DirectDraw surface.

### `prcOldDest` [in]

Pointer to the rectangle representing the old destination position of the rectangle in the overlay surface.

### `bNewVisible` [in]

Boolean specifying whether the new window is visible. **TRUE** means the new window is visible.

### `prcNewSrc` [in]

Pointer to the rectangle representing the new source position of the DirectDraw surface.

### `prcNewDest` [in]

Pointer to the rectangle representing the new destination position of the rectangle in the overlay surface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid parameter. |

## Remarks

The application should call this method once before the overlay-related change occurs and once after the changes are done. In the call before the change, the overlay change doesn't happen until the application completes executing this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideoCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideocallback)