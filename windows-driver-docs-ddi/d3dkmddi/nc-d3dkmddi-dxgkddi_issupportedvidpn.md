# DXGKDDI_ISSUPPORTEDVIDPN callback function

## Description

The *DxgkDdiIsSupportedVidPn* function determines whether a specified VidPN is supported on a display adapter.

## Parameters

### `hAdapter` [in]

A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pIsSupportedVidPn` [in, out]

A pointer to a [DXGKARG_ISSUPPORTEDVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_issupportedvidpn) structure. On input, the caller supplies the **hDesiredVidPn** member of the structure. On return, the **IsVidPnSupported** member receives a Boolean value that indicates whether the VidPN is supported (**TRUE**) or not supported (**FALSE**).

## Return value

*DxgkDdiIsSupportedVidPn* returns one of the following values

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The topology of the VidPN is valid. The IsVidPnSupported structure member is set to either TRUE or FALSE.|
|STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY|The topology of the VidPN implementation is invalid. The IsVidPnSupported structure member is set to FALSE.|
|STATUS_NO_MEMORY|The function failed because it was unable to allocate memory.|

## Remarks

For more information about the analysis that this function must perform, see [Determining Whether a VidPN is Supported on a Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/determining-whether-a-vidpn-is-supported-on-a-display-adapter).

If pIsSupportedVidPnArg->hDesiredVidPn is zero, *DxgkDdiIsSupportedVidPn* must set pIsSupportedVidPnArg->IsVidPnSupported to **TRUE**, the idea being that the display adapter can always be configured to display nothing.

*DxgkDdiIsSupportedVidPn* should be made pageable.

## See also

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)