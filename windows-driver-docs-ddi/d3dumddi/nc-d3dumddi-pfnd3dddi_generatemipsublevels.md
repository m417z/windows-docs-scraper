# PFND3DDDI_GENERATEMIPSUBLEVELS callback function

## Description

The *GenerateMipSubLevels* function regenerates the sublevels of a MIP-map texture.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_GENERATEMIPSUBLEVELS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_generatemipsublevels) structure that describes how to generate the sublevels of a MIP-map texture.

## Return value

*GenerateMipSubLevels* returns S_OK or an appropriate error result if the sublevels of a MIP-map texture are not successfully generated.

## Remarks

After the user-mode display driver performs an operation that accesses only the top level of a MIP-map texture, the Microsoft Direct3D runtime calls the driver's *GenerateMipSubLevels* function to notify the driver to automatically regenerate the sublevels of the MIP-map texture by using a specific filter type.

## See also

[D3DDDIARG_GENERATEMIPSUBLEVELS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_generatemipsublevels)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)