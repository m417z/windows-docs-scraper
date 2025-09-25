# IWiaVideo::DestroyVideo

## Description

The **IWiaVideo::DestroyVideo** method shuts down the streaming video. To restart video playback, the application must call one of the [IWiaVideo](https://learn.microsoft.com/windows/desktop/api/wiavideo/nn-wiavideo-iwiavideo) CreateVideo methods again.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method only after a successful call to [IWiaVideo::CreateVideoByWiaDevID](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobywiadevid), [IWiaVideo::CreateVideoByDevNum](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobydevnum), or [IWiaVideo::CreateVideoByName](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobyname).