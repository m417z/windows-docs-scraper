# IWiaVideo::Pause

## Description

The **IWiaVideo::Pause** method pauses video playback.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method only after a successful call to [IWiaVideo::CreateVideoByWiaDevID](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobywiadevid), [IWiaVideo::CreateVideoByDevNum](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobydevnum), or [IWiaVideo::CreateVideoByName](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobyname).