# D3D10DDI_ADAPTERFUNCS structure

## Description

The D3D10DDI_ADAPTERFUNCS structure contains functions that the user-mode display driver can implement to communicate with a graphics adapter object.

## Members

### `pfnCalcPrivateDeviceSize`

A pointer to the driver's [CalcPrivateDeviceSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedevicesize) function that specifies the size of a memory block that the user-mode display driver requires from the Microsoft Direct3D runtime to store frequently-accessed data.

### `pfnCreateDevice`

A pointer to the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function that creates a representation of a display device that handles a collection of rendering state.

### `pfnCloseAdapter`

A pointer to the driver's [CloseAdapter(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_closeadapter) function that releases resources for a graphics adapter object.

## See also

[CalcPrivateDeviceSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatedevicesize)

[CloseAdapter(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_closeadapter)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter)

[OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter)