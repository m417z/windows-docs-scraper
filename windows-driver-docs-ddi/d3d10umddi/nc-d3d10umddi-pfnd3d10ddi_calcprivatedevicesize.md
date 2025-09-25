# PFND3D10DDI_CALCPRIVATEDEVICESIZE callback function

## Description

The **CalcPrivateDeviceSize** function determines the size of a memory region that the user-mode display driver requires from the Microsoft Direct3D runtime to store frequently-accessed data.

## Parameters

### `unnamedParam1`

*hAdapter* [in]

A handle that identifies the graphics adapter.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3D10DDIARG_CALCPRIVATEDEVICESIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_calcprivatedevicesize) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

## Return value

**CalcPrivateDeviceSize** returns the size of the memory region that the driver requires to store frequently-accessed data.

## See also

[D3D10DDIARG_CALCPRIVATEDEVICESIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_calcprivatedevicesize)