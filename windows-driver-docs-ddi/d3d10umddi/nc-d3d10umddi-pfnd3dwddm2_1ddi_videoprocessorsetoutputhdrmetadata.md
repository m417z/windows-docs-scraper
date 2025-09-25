# PFND3DWDDM2_1DDI_VIDEOPROCESSORSETOUTPUTHDRMETADATA callback function

## Description

Implemented by the client driver to include HDR metadata to allow the video processor to optimize video for display. This callback sets the maximum brightness capability (in nits) of the display on which the content will be presented.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hVideoProcessor`

A handle to the video processor object.

### `Type`

Indicates the type of the HDR metadata provided.

### `Size`

Indicates the type of the HDR metadata provided.

* For D3DDDI_HDR_METADATA_TYPE_NONE, the size should be 0.
* For D3DDDI_HDR_METADATA_TYPE_HDR10, the size is sizeof(D3DDDI_HDR_METADATA_HDR10).

### `pMetaData`

Points to a structure containing the HDR metadata.

* For D3DDDI_HDR_METADATA_TYPE_NONE, this should be NULL.
* For D3DDDI_HDR_METADATA_TYPE_HDR10, this is a pointer to a DD3DDDI_HDR_METADATA_HDR10 structure.

## Prototype

```cpp
//Declaration

PFND3DWDDM2_1DDI_VIDEOPROCESSORSETOUTPUTHDRMETADATA Pfnd3dwddm21DdiVideoprocessorsetoutputhdrmetadata;

// Definition

VOID Pfnd3dwddm21DdiVideoprocessorsetoutputhdrmetadata
(
	D3D10DDI_HDEVICE hDevice
	D3D11_1DDI_HVIDEOPROCESSOR hVideoProcessor
	D3DDDI_HDR_METADATA_TYPE Type
	UINT Size
	CONST VOID *pMetaData
)
{...}

```

## Remarks

When processing an HDR stream, the driver may use this brightness information to tone map the video content to optimize it for the output display.

## See also

[D3DWDDM2_1DDI_VIDEODEVICEFUNCS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_1ddi_videodevicefuncs)