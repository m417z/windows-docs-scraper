# PDXVAHDSW_CreateVideoProcessor callback function

## Description

Creates a software Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor plug-in.

## Parameters

### `hDevice` [in]

A handle to the plug-in DXVA-HD device that creates the video processor.

### `pVPGuid` [in]

A GUID that identifies the video processor to create.

### `phVideoProcessor` [out]

Receives a handle to the software video processor.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHDSW_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahdsw_callbacks)

[IDXVAHD_Device::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideoprocessor)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)