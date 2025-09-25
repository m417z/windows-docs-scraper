# _D3DDDIARG_DXVAHD_CREATEVIDEOPROCESSOR structure

## Description

The D3DDDIARG_DXVAHD_CREATEVIDEOPROCESSOR structure describes a Microsoft DirectX Video Acceleration (DirectX VA) video processor to create.

## Members

### `pVPGuid` [in]

A pointer to the GUID that represents a DirectX VA video processor to create. The Microsoft Direct3D runtime can call the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to query (D3DDDICAPS_DXVAHD_GETVPCAPS) for the capabilities of the video processors that the driver supports. Each **VPGuid** member of the [DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps) structure in the array that the driver's **GetCaps** returns specifies a video processor that the driver supports.

### `hVideoProcessor` [out]

A handle to the video processor. The user-mode display driver must set this handle to a value that the Microsoft Direct3D runtime can use to identify the video processor in subsequent calls.

## See also

[CreateVideoProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_createvideoprocessor)

[DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps)