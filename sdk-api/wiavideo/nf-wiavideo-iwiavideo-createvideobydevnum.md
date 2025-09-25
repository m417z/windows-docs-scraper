# IWiaVideo::CreateVideoByDevNum

## Description

The **IWiaVideo::CreateVideoByDevNum** method creates a connection to a streaming video device with the device number obtained from a Directshow enumeration.

## Parameters

### `uiDeviceNumber` [in]

Type: **UINT**

Specifies the video device's Directshow device number.

### `hwndParent` [in]

Type: **HWND**

Specifies the window in which to display the streaming video.

### `bStretchToFitParent` [in]

Type: **BOOL**

Specifies whether the video display is stretched to fit the parent window. Set this parameter to **TRUE** if the display should be stretched to fit the parent window; otherwise, set to **FALSE**.

### `bAutoBeginPlayback` [in]

Type: **BOOL**

Specifies whether the streaming video begins playback as soon as this method returns. Set this parameter to **TRUE** to cause immediate playback; set it to **FALSE** to require a call to [IWiaVideo::Play](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-play) before video playback begins.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

By default, the video is displayed in the video device's default resolution. If *bStretchToFitParent* is set to **TRUE**, the video display fills the window.