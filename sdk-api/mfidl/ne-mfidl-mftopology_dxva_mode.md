# MFTOPOLOGY_DXVA_MODE enumeration

## Description

Specifies whether the topology loader enables Microsoft DirectX Video Acceleration (DXVA) in the topology.

## Constants

### `MFTOPOLOGY_DXVA_DEFAULT:0`

The topology loader enables DXVA
on the decoder if possible, and drops optional Media Foundation transforms (MFTs) that do not support DXVA.

### `MFTOPOLOGY_DXVA_NONE:1`

The topology loader disables all video acceleration. This setting forces software processing, even when the decoder supports DXVA.

### `MFTOPOLOGY_DXVA_FULL:2`

The topology loader enables DXVA on every MFT that supports it.

## Remarks

This enumeration is used with the [MF_TOPOLOGY_DXVA_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-dxva-mode) topology attribute.

If an MFT supports DXVA, the MFT must return **TRUE** for the [MF_SA_D3D_AWARE](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d-aware-attribute) attribute. To enable DXVA, the topology loader calls [IMFTransform::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage) on the MFT, passing the MFT a pointer to the [IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9) interface. The topology loader gets the **IDirect3DDeviceManager9** pointer from the media sink for the video stream. Typically the enhanced video renderer (EVR) is the media sink.

Previous versions of Microsoft Media Foundation supported DXVA only for decoders.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)