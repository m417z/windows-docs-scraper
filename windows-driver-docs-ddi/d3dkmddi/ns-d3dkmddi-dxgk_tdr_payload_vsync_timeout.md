## Description

The **DXGK_TDR_PAYLOAD_VSYNC_TIMEOUT** structure contains the payload for a [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) call when **TdrType** is **DXGK_TDR_TYPE_VSYNC_TIMEOUT**.

## Members

### `VidPnSourceId`

[in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source that timed out.

### `LayerIndex`

[in] the MPO plane index that timed out.

### `PresentId`

[in] The PresentId that timed out.

## Remarks

For more information, see [TDR debuggability improvements](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-debuggability-improvements).

## See also

[**DXGK_TDR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_tdr_type)

[**DXGKARG_COLLECTDBGINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_collectdbginfo2)

[**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2)