# _DXVA_ProcAmpControlQueryRange structure

## Description

The DXVA_ProcAmpControlQueryRange structure contains the minimum, maximum, step size, and default value for each ProcAmp property.

## Members

### `Size`

Specifies the size of this structure in bytes.

### `ProcAmpControlProp`

Specifies a [DXVA_ProcAmpControlProp](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_procampcontrolprop) structure that indicates the supported ProcAmp control properties.

### `VideoDesc`

Specifies a [DXVA_VideoDesc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videodesc) structure that provides the driver with a description of the video that the ProcAmp adjustment is going to be applied to. Drivers may adjust their ProcAmp feature support for particular video streams.

## See also

[DXVA_ProcAmpControlProp](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_procampcontrolprop)

[DXVA_VideoDesc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videodesc)