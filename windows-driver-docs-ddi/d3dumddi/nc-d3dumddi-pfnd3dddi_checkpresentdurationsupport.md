# PFND3DDDI_CHECKPRESENTDURATIONSUPPORT callback function

## Description

Called by the Microsoft Direct3D runtime to request that the user-mode display driver get hardware device capabilities for seamlessly switching to a new monitor refresh rate. Optionally implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pPresentDurationSupport* [in]

A pointer to a [D3DDDIARG_CHECKPRESENTDURATIONSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_checkpresentdurationsupport) structure that contains info on hardware device support for seamlessly switching to a new monitor refresh rate.

## Return value

If this routine succeeds, it returns **S_OK**. The driver should always return a success code.

## See also

[D3DDDIARG_CHECKPRESENTDURATIONSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_checkpresentdurationsupport)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)