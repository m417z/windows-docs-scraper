# D3D10_2DDICAPS_TYPE enumeration

## Description

The D3D10_2DDICAPS_TYPE enumeration type contains values that identify the type of capability information that is retrieved from a call to the driver's [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

## Constants

### `D3D11DDICAPS_THREADING`

The driver retrieves a pointer to a [D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps) structure that describes the threading capabilities that the driver supports.

### `D3D11DDICAPS_SHADER`

The driver retrieves a pointer to a [D3D11DDI_SHADER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_shader_caps) structure that describes the shader capabilities that the driver supports.

### `D3D11DDICAPS_3DPIPELINESUPPORT`

The driver retrieves a pointer to a [D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps) structure that describes the pipeline capabilities that the driver supports.

### `D3D11_1DDICAPS_D3D11_OPTIONS`

The driver retrieves a pointer to a [D3D11_1DDI_D3D11_OPTIONS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_d3d11_options_data) structure that specifies options to provide data to the user-mode driver.

Supported starting with Windows 8.

### `D3D11_1DDICAPS_ARCHITECTURE_INFO`

The driver retrieves a pointer to a [D3DDDICAPS_ARCHITECTURE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_architecture_info) structure that describes information about Direct3D 11.1 adapter architecture.

Supported starting with Windows 8.

### `D3D11_1DDICAPS_SHADER_MIN_PRECISION_SUPPORT`

The driver retrieves a pointer to a [D3DDDICAPS_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_shader_min_precision_support) structure that describes the precision support options for shaders in the user-mode display driver.

Supported starting with Windows 8.

### `D3DWDDM1_3DDICAPS_D3D11_OPTIONS1`

The driver retrieves a pointer to a [D3DWDDM1_3DDI_D3D11_OPTIONS_DATA1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_d3d11_options_data1) structure that describes the tiled resource support options in the user-mode display driver.

Supported starting with Windows 8. Used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDICAPS_MARKER`

Supported starting with Windows 8. Used by WDDM 1.3 and later drivers.

### `D3DWDDM2_0DDICAPS_D3D11_OPTIONS2`

### `D3DWDDM2_0DDICAPS_MEMORY_ARCHITECTURE`

### `D3DWDDM2_0DDICAPS_TEXTURE_LAYOUT_SETS`

### `D3DWDDM2_0DDICAPS_TEXTURE_LAYOUT`

### `D3DWDDM2_0DDICAPS_SWIZZLE_PATTERN`

### `D3DWDDM2_0DDICAPS_D3D11_OPTIONS3`

### `D3DWDDM2_0DDICAPS_GPUVA_CAPS`

### `D3DWDDM2_0DDICAPS_TEXTURE_LAYOUT1`

### `D3DWDDM2_2DDICAPS_SHADERCACHE`

### `D3DWDDM2_2DDICAPS_TEXTURE_LAYOUT`

### `D3DWDDM2_2DDICAPS_SWIZZLE_PATTERN`

### `D3D12_DOWNLEVEL_DDICAPS_UMDFILENAME`

Supported starting from Windows 10, version 1901. Used by WDDM 2.6 and later drivers.

## Remarks

To allow a driver to unify capability concepts, the values in the D3D10_2DDICAPS_TYPE enumeration are set up so they do not overlap with the values in the [D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type) enumeration.

## See also

[D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps)

[D3D11DDI_SHADER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_shader_caps)

[D3D11DDI_THREADING_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_threading_caps)

[D3D11_1DDI_D3D11_OPTIONS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_d3d11_options_data)

[D3DDDICAPS_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicaps_shader_min_precision_support)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DWDDM1_3DDI_D3D11_OPTIONS_DATA1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_d3d11_options_data1)