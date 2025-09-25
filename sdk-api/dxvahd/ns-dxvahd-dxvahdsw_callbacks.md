# DXVAHDSW_CALLBACKS structure

## Description

Contains pointers to functions implemented by a software plug-in for Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `CreateDevice`

Function pointer of type [PDXVAHDSW_CreateDevice](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_createdevice).

### `ProposeVideoPrivateFormat`

Function pointer of type [PDXVAHDSW_ProposeVideoPrivateFormat](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_proposevideoprivateformat).

### `GetVideoProcessorDeviceCaps`

Function pointer of type [PDXVAHDSW_GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessordevicecaps).

### `GetVideoProcessorOutputFormats`

Function pointer of type [PDXVAHDSW_GetVideoProcessorOutputFormats](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessoroutputformats).

### `GetVideoProcessorInputFormats`

Function pointer of type [PDXVAHDSW_GetVideoProcessorInputFormats](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessorinputformats).

### `GetVideoProcessorCaps`

Function pointer of type [PDXVAHDSW_GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessorcaps).

### `GetVideoProcessorCustomRates`

Function pointer of type [PDXVAHDSW_GetVideoProcessorCustomRates](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessorcustomrates).

### `GetVideoProcessorFilterRange`

Function pointer of type [PDXVAHDSW_GetVideoProcessorFilterRange](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessorfilterrange).

### `DestroyDevice`

Function pointer of type [PDXVAHDSW_DestroyDevice](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_destroydevice).

### `CreateVideoProcessor`

Function pointer of type [PDXVAHDSW_CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_createvideoprocessor).

### `SetVideoProcessBltState`

Function pointer of type [PDXVAHDSW_SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_setvideoprocessbltstate).

### `GetVideoProcessBltStatePrivate`

Function pointer of type [PDXVAHDSW_GetVideoProcessBltStatePrivate](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessbltstateprivate).

### `SetVideoProcessStreamState`

Function pointer of type [PDXVAHDSW_SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_setvideoprocessstreamstate).

### `GetVideoProcessStreamStatePrivate`

Function pointer of type [PDXVAHDSW_GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_getvideoprocessstreamstateprivate).

### `VideoProcessBltHD`

Function pointer of type [PDXVAHDSW_VideoProcessBltHD](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_videoprocessblthd).

### `DestroyVideoProcessor`

Function pointer of type [PDXVAHDSW_DestroyVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_destroyvideoprocessor).

## Remarks

If you provide a software plug-in for DXVA-HD, the plug-in must implement a set of functions that are defined by the function pointer types in this structure.

At initialization, the DXVA-HD runtime calls the plug-in device's [PDXVAHDSW_Plugin](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_plugin) function. This function fills in a **DXVAHDSW_CALLBACKS** structure with pointers to the set of functions that are implemented by the plug-in device. When the application calls DXVA-HD methods, the DXVA-HD runtime calls the corresponding plug-in functions.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[PDXVAHDSW_Plugin](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_plugin)