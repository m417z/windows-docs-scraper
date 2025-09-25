# PFND3DDDI_SETLIGHT callback function

## Description

The *SetLight* function sets properties for a light source.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETLIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setlight) structure that describes how to set the light source.

### `unnamedParam3`

*pLightProperties* [in]

A pointer to a [D3DDDI_LIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_light) structure that describes the light properties to set.

## Return value

*SetLight* returns S_OK or an appropriate error result if the light properties are not successfully set.

## Remarks

Light properties describe the type and color of a light source. Depending on the type of light that is being used, a light can have properties for attenuation and range or for spotlight effects. However, not all types of lights will use all of the properties. For more information about light properties, see the Microsoft Windows SDK documentation.

## See also

[D3DDDIARG_SETLIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setlight)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_LIGHT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_light)