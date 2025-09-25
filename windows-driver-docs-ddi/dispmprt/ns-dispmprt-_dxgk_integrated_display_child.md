# DXGK_INTEGRATED_DISPLAY_CHILD structure

## Description

The **DXGK_INTEGRATED_DISPLAY_CHILD** structure provides information about the connected integrated display.

## Members

### `InterfaceTechnology`

Provides the type of connection used for the integrated display. Typically, **InterfaceTechnology** would be one of the inherently internal display types:

* D3DKMDT_VOT_INTERNAL
* D3DKMDT_VOT_LVDS
* D3DKMDT_VOT_DISPLAYPORT_EMBEDDED
* D3DKMDT_VOT_UDI_EMBEDDED

However, since it's common to use external connector types to connect integrated displays in larger form factor systems with a built-in display such as all-in-one systems, the following digital connection types are also allowed:

* D3DKMDT_VOT_DVI
* D3DKMDT_VOT_HDMI
* D3DKMDT_VOT_D_JPN
* D3DKMDT_VOT_SDI
* D3DKMDT_VOT_DISPLAYPORT_EXTERNAL
* D3DKMDT_VOT_UDI_EXTERNAL

### `DescriptorLength`

The size in bytes of the descriptor in the **Descriptor** field of the [**DXGK_QUERYINTEGRATEDDISPLAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_queryintegrateddisplayout) structure.

## See also

[**DXGK_CHILD_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities)

[**DXGK_QUERYINTEGRATEDDISPLAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_queryintegrateddisplayout)