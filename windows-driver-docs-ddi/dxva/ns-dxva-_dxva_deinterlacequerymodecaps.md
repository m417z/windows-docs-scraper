# _DXVA_DeinterlaceQueryModeCaps structure

## Description

The DXVA_DeinterlaceQueryModeCaps structure describes a deinterlacing mode.

## Members

### `Size`

Indicates the size of this structure.

### `Guid`

Specifies for which mode of deinterlacing the driver should return capabilities.

### `VideoDesc`

Specifies a [DXVA_VideoDesc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videodesc) structure that describes the type of video that is to be deinterlaced.

## Remarks

The driver receives the DXVA_DeinterlaceQueryModeCaps structure with all members assigned in a query for capabilities about a particular deinterlacing mode. The driver returns capabilities in a [DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps) structure.

## See also

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)

[DXVA_DeinterlaceQueryAvailableModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacequeryavailablemodes)

[DXVA_VideoDesc](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_videodesc)