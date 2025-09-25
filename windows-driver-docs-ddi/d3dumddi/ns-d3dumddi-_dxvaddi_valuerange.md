# _DXVADDI_VALUERANGE structure

## Description

The DXVADDI_VALUERANGE structure describes values of a property (such as, the value spread and default value).

## Members

### `MinValue` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the minimum value that is allowed for a given property.

### `MaxValue` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the maximum value that is allowed for a given property.

### `DefaultValue` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the default value for a given property.

### `StepSize` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the step size increment for a given property.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[DXVADDI_QUERYPROCAMPINPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_queryprocampinput)

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)