## Description

Called asynchronously by the platform on successful establishment of a requested communication channel with a video renderer effect.

## Parameters

### `pAppServiceConnection`

An **IUnknown** representing the app service connection object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called asynchronously after the video renderer effect sets the [MF_VIDEO_RENDERER_EFFECT_APP_SERVICE_NAME](https://learn.microsoft.com/windows/win32/medfound/mf-video-renderer-effect-app-service-name) property.

## See also