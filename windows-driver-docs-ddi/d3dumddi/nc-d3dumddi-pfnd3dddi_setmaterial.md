# PFND3DDDI_SETMATERIAL callback function

## Description

The *SetMaterial* function sets the material properties that devices on the system use to create the required effect during rendering.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETMATERIAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setmaterial) structure that describes the material properties that are used for rendering.

## Return value

*SetMaterial* returns S_OK or an appropriate error result if the material properties are not successfully set.

## Remarks

Material properties detail a material's diffuse reflection, ambient reflection, light emission, and specular highlighting characteristics. The Microsoft Direct3D runtime uses the [D3DDDIARG_SETMATERIAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setmaterial) structure to pass all of the material property information to the user-mode display driver. Material properties affect the colors that the Direct3D runtime uses to rasterize polygons that use the material. With the exception of the specular property, each of the properties is described as an RGBA color that represents how much of the red, green, and blue parts of a given type of light it reflects and an alpha blending factor (the alpha component of the RGBA color). The material's specular property is described in two parts: color and power. For more information about material properties, see the Microsoft Windows SDK documentation.

## See also

[D3DDDIARG_SETMATERIAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setmaterial)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)