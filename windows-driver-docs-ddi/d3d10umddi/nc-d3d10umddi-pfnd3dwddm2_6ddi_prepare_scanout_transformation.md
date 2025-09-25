# PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION callback function

## Description

Invokes the driver to schedule work to perform the necessary transformations from the input resource, to the "shadow" allocation which will actually be scanned out. The runtime may request that the driver only update a sub-region, if only a small portion of the resource has changed since the last time this was invoked.

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

### `pSubRect`

Pointer to a D3D10_DDI_RECT.

## Prototype

```
//Declaration

PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION Pfnd3dwddm26DdiPrepareScanoutTransformation;

// Definition

void Pfnd3dwddm26DdiPrepareScanoutTransformation
(
	D3D10DDI_HDEVICE Arg1
	D3D10DDI_HRESOURCE Arg2
	UINT Subresource
	D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId
	UINT PlaneIdx
	D3D10_DDI_RECT *pSubRect
)
{...}

```

## Remarks

## See also

[PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_6ddi_query_scanout_caps)