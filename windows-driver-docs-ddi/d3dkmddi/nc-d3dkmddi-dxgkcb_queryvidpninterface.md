# DXGKCB_QUERYVIDPNINTERFACE callback function

## Description

**DXGKCB_QUERYVIDPNINTERFACE** obtains a pointer to a [**DXGK_VIDPN_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) structure, which contains pointers to functions that the display miniport driver can call to inspect and alter a VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided the display miniport driver with this handle by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnInterfaceVersion` [in]

A [DXGK_VIDPN_INTERFACE_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_vidpn_interface_version) enumerator that specifies the version of the VidPN interface being requested. Callers must set this parameter to **DXGK_VIDPN_INTERFACE_VERSION_V1**.

### `ppVidPnInterface` [out]

A pointer to a variable that receives a pointer to the [DXGK_VIDPN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) structure.

## Return value

**DxgkCbQueryVidPnInterface** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|The value passed to ppVidPnInterface is not valid.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle passed to hVidPn is not valid.|
|STATUS_NOT_SUPPORTED|The interface version specified by VidPnInterfaceVersion is not supported.|

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, the kernel-mode driver calls **DxgkCbQueryVidPnInterface** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[VidPN Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces)

[Monitor Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_monitorsourcemodeset_interface)

[VidPN Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface)

[VidPN Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface)

[VidPN Target Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface)

[VidPN Topology Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntopology_interface)