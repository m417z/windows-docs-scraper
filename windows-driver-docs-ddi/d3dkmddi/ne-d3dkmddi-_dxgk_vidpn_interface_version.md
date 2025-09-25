# DXGK_VIDPN_INTERFACE_VERSION enumeration

## Description

The **DXGK_VIDPN_INTERFACE_VERSION** enumeration indicates the version of a video present network (VidPN) interface.

## Constants

### `DXGK_VIDPN_INTERFACE_VERSION_UNINITIALIZED`

Indicates that a variable of type DXGK_VIDPN_INTERFACE_VERSION has not yet been assigned a meaningful value.

### `DXGK_VIDPN_INTERFACE_VERSION_V1`

Indicates version 1 of the VidPN interface.

### `DXGK_VIDPN_INTERFACE_VERSION_V2`

Indicates version 2 of the VidPN interface.

## Remarks

The **VidPnInterfaceVersion** parameter of the [**DxgkCbQueryVidPnInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryvidpninterface) function and the **Version** member of the [**DXGK_VIDPN_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpn_interface) structure are DXGK_VIDPN_INTERFACE_VERSION values.

## See also

[VidPn Objects and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces)