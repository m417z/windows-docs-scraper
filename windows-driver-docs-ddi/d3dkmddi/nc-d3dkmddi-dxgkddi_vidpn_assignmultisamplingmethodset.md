# DXGKDDI_VIDPN_ASSIGNMULTISAMPLINGMETHODSET callback function

## Description

The **DXGKDDI_VIDPN_ASSIGNMULTISAMPLINGMETHODSET** function assigns a set of multisampling methods to a particular video-present source in a specified VidPN.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [**DxgkDdiEnumVidPnCofuncModality**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality).

### `VidPnSourceId` [in]

An integer that identifies one of the video present sources associated with the VidPN object.

### `NumMethods` [in]

The number of elements in the **pSupportedMethodSet** array.

### `pSupportedMethodSet` [in]

A pointer to an array of [**D3DDDI_MULTISAMPLINGMETHOD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_multisamplingmethod) structures, each of which describes a multisampling method.

## Return value

The **DXGKDDI_VIDPN_ASSIGNMULTISAMPLINGMETHODSET** function returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE|The identifier supplied in VidPnSourceId was invalid.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate enough memory.|

This function might also return other error codes that are defined in Ntstatus.h.

## See also

[**DxgkDdiEnumVidPnCofuncModality**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)