# PFND3DDDI_UPDATEWINFO callback function

## Description

The *UpdateWInfo* function updates the w range for w buffering.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_WINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_winfo) structure that describes the w range for w buffering.

## Return value

*UpdateWInfo* returns S_OK or an appropriate error result if the w range is not successfully updated.

## See also

[D3DDDIARG_WINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_winfo)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)