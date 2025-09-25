## Description

The **DXGK_QUERYINTEGRATEDDISPLAYOUT** structure is used to output queried information for an integrated display.

## Members

### `Flags`

A [**DXGK_INTEGRATEDDISPLAYFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_integrateddisplayflags) structure that contains flags describing properties of the integrated display.

### `NativeTiming`

A [**D3DKMDT_VIDEO_SIGNAL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) structure that contains information about a video signal driven by a video output on a display adapter.

### `LinkCapabilities`

A [**DXGK_MONITORLINKINFO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_monitorlinkinfo_capabilities) structure with flags that describe capabilities for driving the monitor.

### `Colorimetry`

A [**DXGK_COLORIMETRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_colorimetry) enumeration that indicates the colorimetry support of the display.

### `DisplayTechnology`

A [**DXGK_DISPLAY_TECHNOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_display_technology) enumeration that describes the technology used by the display.

### `IntendedUsage`

A [**DXGK_DISPLAY_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_display_usage) enumeration that specifies the intended usage of the display.

### `Instance`

A BYTE value that uniquely identifies the instance of the integrated display being queried.

### `DescriptorType`

A [**DXGK_DISPLAY_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_display_descriptor_type) enumeration that specifies the display descriptor type in **Descriptor**.

### `Descriptor[1]`

A BYTE array that contains the descriptor data. The type and format of this data depend on the **DescriptorType**.

## Remarks

## See also

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DXGKDDI_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)