# DXGKDDI_VIDPN_GETTOPOLOGY callback function

## Description

The **pfnGetTopology** function returns a handle to the VidPN topology object contained by a specified VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `phVidPnTopology` [out]

A pointer to a variable that receives a handle to the VidPN topology object.

### `ppVidPnTopologyInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_VIDPNTOPOLOGY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntopology_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the VidPN topology object.

## Return value

The **pfnGetTopology** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|

## Remarks

The display miniport driver does not need to release the handle that it receives in *phVidPnTopology*.

The lifetime of the DXGK_VIDPNTOPOLOGY_INTERFACE structure returned in *ppVidPnTopologyInterface* is owned by the operating system. Using this ownership scheme, the operating system can migrate to newer implementations at run time without breaking clients of the interface.

## See also

[DXGK_VIDPNTOPOLOGY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntopology_interface)

[VidPN Topology Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)