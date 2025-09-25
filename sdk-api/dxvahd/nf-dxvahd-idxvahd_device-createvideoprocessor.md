# IDXVAHD_Device::CreateVideoProcessor

## Description

Creates a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Parameters

### `pVPGuid` [in]

A GUID that identifies the video processor to create. This GUID must equal the value of the **VPGuid** member from one of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structures retrieved by the [IDXVAHD_Device::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcaps) method.

### `ppVideoProcessor` [out]

Receives a pointer to the [IDXVAHD_VideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_videoprocessor) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device)