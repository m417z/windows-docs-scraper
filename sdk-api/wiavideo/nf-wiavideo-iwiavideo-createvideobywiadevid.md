# IWiaVideo::CreateVideoByWiaDevID

## Description

The **IWiaVideo::CreateVideoByWiaDevID** method creates a connection to a streaming video device from its WIA_DIP_DEV_ID property.

## Parameters

### `bstrWiaDeviceID` [in]

Type: **BSTR**

Specifies the value of the video device's WIA_DIP_DEV_ID property.

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

In order for the function to succeed, the [IWiaVideo::ImagesDirectory](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-get_imagesdirectory) property must be specified first. Thus, the caller must first call "put_ImagesDirectory" to specify the full path of the directory in which the captured still images will be stored.

## See also

[Enumerating System Devices](https://learn.microsoft.com/windows/desktop/wia/-wia-enumerating-system-devices)

[IWiaVideo](https://learn.microsoft.com/windows/desktop/api/wiavideo/nn-wiavideo-iwiavideo)