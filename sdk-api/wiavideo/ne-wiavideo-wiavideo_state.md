# WIAVIDEO_STATE enumeration

## Description

The **WIAVIDEO_STATE** enumeration is used to specify the current state of a video stream.

**Note** Windows Image Acquisition (WIA) does not support video devices in Windows Server 2003, Windows Vista, and later. For those versions of the Windows, use [DirectShow](https://learn.microsoft.com/previous-versions/ms783323(v=vs.85)) to acquire images from video.

## Constants

### `WIAVIDEO_NO_VIDEO:1`

No video stream exists. Call [IWiaVideo::CreateVideoByWiaDevID](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobywiadevid), [IWiaVideo::CreateVideoByDevNum](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobydevnum), or [IWiaVideo::CreateVideoByName](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-createvideobyname) to create a video.

### `WIAVIDEO_CREATING_VIDEO:2`

One of the [IWiaVideo](https://learn.microsoft.com/windows/desktop/api/wiavideo/nn-wiavideo-iwiavideo) CreateVideo methods was called and WIA is in the process of creating the video stream.

### `WIAVIDEO_VIDEO_CREATED:3`

A video stream has been successfully created, but playback has not yet started.

### `WIAVIDEO_VIDEO_PLAYING:4`

A video stream has been successfully created, and the video is playing. The application can now call the [IWiaVideo::TakePicture](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-takepicture) method.

### `WIAVIDEO_VIDEO_PAUSED:5`

A video stream has been successfully created, and the video is paused. The application can now call the [IWiaVideo::TakePicture](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-takepicture) method.

### `WIAVIDEO_DESTROYING_VIDEO:6`

The application called [IWiaVideo::DestroyVideo](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-destroyvideo) method, and WIA is in the process of destroying the video stream.

## See also

[IWiaVideo::GetCurrentState](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-getcurrentstate)