# PDXVAHDSW_CreateDevice callback function

## Description

Creates an instance of a software plug-in Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `pD3DDevice` [in]

A pointer to the **IDirect3DDevice9Ex** interface of the Direct3D device.

### `phDevice` [out]

Receives a handle to the plug-in DXVA-HD device.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)