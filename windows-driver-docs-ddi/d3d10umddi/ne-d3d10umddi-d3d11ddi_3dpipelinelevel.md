# D3D11DDI_3DPIPELINELEVEL enumeration

## Description

The D3D11DDI_3DPIPELINELEVEL enumeration type contains values that identify the pipeline level that the driver supports, which is retrieved from a call to the driver's [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function.

## Constants

### `D3D11DDI_3DPIPELINELEVEL_10_0`

The driver supports Direct3D version 10 pipeline.

### `D3D11DDI_3DPIPELINELEVEL_10_1`

The driver supports Direct3D version 10.1 pipeline.

### `D3D11DDI_3DPIPELINELEVEL_11_0`

The driver supports Direct3D version 11 pipeline.

### `D3D11_1DDI_3DPIPELINELEVEL_11_1`

Supported beginning with Windows 8.

The driver supports Direct3D version 11.1 pipeline.

### `D3D11_1DDI_3DPIPELINELEVEL_9_1`

Supported beginning with Windows 8.

The driver supports Direct3D version 9.1 pipeline.

### `D3D11_1DDI_3DPIPELINELEVEL_9_2`

Supported beginning with Windows 8.

The driver supports Direct3D version 9.2 pipeline.

### `D3D11_1DDI_3DPIPELINELEVEL_9_3`

Supported beginning with Windows 8.

The driver supports Direct3D version 9.3 pipeline.

### `D3DWDDM2_0DDI_3DPIPELINELEVEL_12_0`

The driver supports Direct3D version 12.0 pipeline.

### `D3DWDDM2_0DDI_3DPIPELINELEVEL_12_1`

The driver supports Direct3D version 12.1 pipeline.

## Remarks

The driver uses one of the values from the D3D11DDI_3DPIPELINELEVEL enumeration and the following macro to encode the 3-D pipeline level:

```cpp
#define D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( Level ) (0x1 << Level)
```

The driver then uses the macro's result in the **Caps** member of the [D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps) structure to provide information to the Direct3D runtime when the runtime calls the driver's [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function with the **Type** member of [D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps) set to D3D11DDICAPS_3DPIPELINESUPPORT.

The driver uses the following constant and macros to extract one of the values from the D3D11DDI_3DPIPELINELEVEL enumeration that represents the 3-D pipeline level to set for a display device. The driver extracts the value from the **Caps** member of D3D11DDI_3DPIPELINESUPPORT_CAPS. The driver uses the 3-D pipeline level to create the appropriate display device when the driver receives a call to its [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

```cpp
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT (0x1)
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK (0x7 << D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT)
#define D3D11DDI_EXTRACT_3DPIPELINELEVEL_FROM_FLAGS( Flags ) \
    ((D3D11DDI_3DPIPELINELEVEL)(((Flags) & D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK) >> \
    D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT))
```

For more information about the Direct3D version 10 pipeline, see [Rendering Pipeline](https://learn.microsoft.com/windows-hardware/drivers/display/rendering-pipeline).

For more information about the Direct3D version 11 pipelines, see [Pipelines for Direct3D Version 11](https://learn.microsoft.com/windows-hardware/drivers/display/pipelines-for-direct3d-version-11).

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps)

[D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)