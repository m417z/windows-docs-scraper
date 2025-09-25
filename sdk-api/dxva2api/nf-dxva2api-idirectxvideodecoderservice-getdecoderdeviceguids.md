# IDirectXVideoDecoderService::GetDecoderDeviceGuids

## Description

Retrieves an array of GUIDs that identifies the decoder devices supported by the graphics hardware.

## Parameters

### `pCount` [out]

Receives the number of GUIDs.

### `pGuids` [out]

Receives an array of GUIDs. The size of the array is retrieved in the *Count* parameter. The method allocates the memory for the array. The caller must free the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_INVALIDCALL** | Error from the Direct3D device. |
| **E_FAIL** | If the Microsoft Basic Display Adapter is being used or the Direct3D 11 device type is the reference rasterizer. These devices do not support video decoders. |

## Remarks

The following decoder GUIDs are defined. Some of these GUIDs have alternate names, shown in parentheses.

| GUID | Description |
| --- | --- |
| DXVA2_ModeH264_A (DXVA2_ModeH264_MoComp_NoFGT) | H.264 motion compensation (MoComp), no film grain technology (FGT). |
| DXVA2_ModeH264_B (DXVA2_ModeH264_MoComp_FGT) | H.264 MoComp, FGT. |
| DXVA2_ModeH264_C (DXVA2_ModeH264_IDCT_NoFGT) | H.264 inverse discrete cosine transform (IDCT), no FGT. |
| DXVA2_ModeH264_D (DXVA2_ModeH264_IDCT_FGT) | H.264 IDCT, FGT. |
| DXVA2_ModeH264_E (DXVA2_ModeH264_VLD_NoFGT) | H.264 VLD, no FGT. |
| DXVA2_ModeH264_F (DXVA2_ModeH264_VLD_FGT) | H.264 variable-length decoder (VLD), FGT. |
| DXVA2_ModeHEVC_VLD_Main | H.265 / HEVC Main profile |
| DXVA2_ModeHEVC_VLD_Main10 | H.265 / HEVC Main 10 profile |
| DXVA2_ModeMPEG2_IDCT | MPEG-2 IDCT. |
| DXVA2_ModeMPEG2_MoComp | MPEG-2 MoComp. |
| DXVA2_ModeMPEG2_VLD | MPEG-2 VLD. |
| DXVA2_ModeVC1_A (DXVA2_ModeVC1_PostProc) | VC-1 post processing. |
| DXVA2_ModeVC1_B (DXVA2_ModeVC1_MoComp) | VC-1 MoComp. |
| DXVA2_ModeVC1_C (DXVA2_ModeVC1_IDCT) | VC-1 IDCT. |
| DXVA2_ModeVC1_D (DXVA2_ModeVC1_VLD) | VC-1 VLD. |
| DXVA2_ModeWMV8_A (DXVA2_ModeWMV8_PostProc) | Windows Media Video 8 post processing. |
| DXVA2_ModeWMV8_B (DXVA2_ModeWMV8_MoComp) | Windows Media Video 8 MoComp. |
| DXVA2_ModeWMV9_A (DXVA2_ModeWMV9_PostProc) | Windows Media Video 9 post processing. |
| DXVA2_ModeWMV9_B (DXVA2_ModeWMV9_MoComp) | Windows Media Video 9 MoComp. |
| DXVA2_ModeWMV9_C (DXVA2_ModeWMV9_IDCT) | Windows Media Video 9 IDCT. |

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoderService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoderservice)