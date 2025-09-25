# IWiaVideo::Play

## Description

Begins playback of streaming video.

## Return value

Type: **HRESULT**

If the method succeeds or the video is already playing, this method returns S_OK. If the method fails, it returns a standard COM error code.

## Remarks

Call this method only after a successful call to [IWiaVideo::CreateVideoByWiaDevID](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobywiadevid), [IWiaVideo::CreateVideoByDevNum](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobydevnum), or [IWiaVideo::CreateVideoByName](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobyname).