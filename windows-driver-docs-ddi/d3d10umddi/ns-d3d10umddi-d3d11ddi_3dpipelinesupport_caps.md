# D3D11DDI_3DPIPELINESUPPORT_CAPS structure

## Description

The D3D11DDI_3DPIPELINESUPPORT_CAPS structure contains display device pipeline capabilities.

## Members

### `Caps` [in]

A value that identifies the pipeline capabilities of the driver.

## Remarks

The driver uses the one of the values from the [D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel) enumeration and the following macro to encode the 3-D pipeline level:

```cpp
#define D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( Level ) (0x1 << Level)
```

The driver then uses the macro's result in the **Caps** member of the D3D11DDI_3DPIPELINESUPPORT_CAPS structure to provide information to the Direct3D runtime when the runtime calls the driver's [GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps) function with the **Type** member of [D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps) set to D3D11DDICAPS_3DPIPELINESUPPORT.

The driver uses the following constant and macros to extract one of the values from the [D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel) enumeration that represents the 3-D pipeline level to set for a display device. The driver extracts the value from the **Caps** member of the D3D11DDI_3DPIPELINESUPPORT_CAPS structure. The driver uses the 3-D pipeline level to create the appropriate display device when the driver receives a call to its [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function.

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

[D3D10_2DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_2ddicaps_type)

[D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)