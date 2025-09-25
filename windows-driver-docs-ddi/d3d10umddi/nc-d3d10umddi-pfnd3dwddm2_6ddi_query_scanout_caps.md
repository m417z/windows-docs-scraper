# PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS callback function

## Description

Queries whether or not a transformation should occur in preparation for a flip operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the device.

### `unnamedParam2`

*hResource* [in]

A handle to the resource that is associated with the allocations.

### `Subresource`

The subresource index.

### `VidPnSourceId`

A zero-based ID of the video present source in a path of a video present network topology.

### `PlaneIdx`

The index of the plane.

### `pFlags`

A [D3DWDDM2_6DDI_SCANOUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_6ddi_scanout_flags) value that indicates the type of transformation.

## Prototype

```
//Declaration

PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS Pfnd3dwddm26DdiQueryScanoutCaps;

// Definition

void Pfnd3dwddm26DdiQueryScanoutCaps
(
	D3D10DDI_HDEVICE Arg1
	D3D10DDI_HRESOURCE Arg2
	UINT Subresource
	D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId
	UINT PlaneIdx
	D3DWDDM2_6DDI_SCANOUT_FLAGS *pFlags
)
{...}

```

## Remarks

In WDDM 2.6, the D3D11 runtime will be updated to call this DDI prior to issuing a full screen or multiplane overlay flip. If the result is that a transformation is required, or that it’s desired and there’s been no API request to disable it, then the runtime will call [PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_prepare_scanout_transformation).

Note that the runtime will not call PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS and PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION during a windowed flip model present in Windows 10, version 1903, which may progress to independent flip, because the runtime does not know whether or not that will occur, and if so, which VidPnSource and plane it will use.

The driver may not set both the D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_REQUIRED and D3DWDDM2_6DDI_SCANOUT_FLAG_TRANSFORMATION_DESIRED flag in [D3DWDDM2_6DDI_SCANOUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_6ddi_scanout_flags).

Regardless of whether a transformation occurs, the driver should indicate to the runtime whether the resulting allocation follows a predictable scanout timing or not, by using the D3DWDDM2_6DDI_SCANOUT_FLAG_UNPREDICTABLE_TIMING flag. This information will be used to adjust the front-buffer rendering safety margins.

## See also