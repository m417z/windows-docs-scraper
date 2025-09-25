# IWiaVideo::GetCurrentState

## Description

The **IWiaVideo::GetCurrentState** method specifies the state of the video stream as a member of the [WIAVIDEO_STATE](https://learn.microsoft.com/windows/win32/api/wiavideo/ne-wiavideo-wiavideo_state) enumeration.

## Parameters

### `pState` [out, retval]

Type: **[WIAVIDEO_STATE](https://learn.microsoft.com/windows/win32/api/wiavideo/ne-wiavideo-wiavideo_state)***

A member of the [WIAVIDEO_STATE](https://learn.microsoft.com/windows/win32/api/wiavideo/ne-wiavideo-wiavideo_state) enumeration that specifies the current state of the video stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.