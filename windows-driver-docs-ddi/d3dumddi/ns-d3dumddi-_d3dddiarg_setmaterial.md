# _D3DDDIARG_SETMATERIAL structure

## Description

The D3DDDIARG_SETMATERIAL structure describes the material properties that are used for rendering.

## Members

### `Diffuse` [in]

A D3DCOLORVALUE structure that indicates the diffuse color of the material. For more information about D3DCOLORVALUE, see the Microsoft Windows SDK documentation.

### `Ambient` [in]

A D3DCOLORVALUE structure that indicates the ambient color of the material.

### `Specular` [in]

A D3DCOLORVALUE structure that indicates the specular color of the material.

### `Emissive` [in]

A D3DCOLORVALUE structure that indicates the emissive color of the material.

### `Power` [in]

A FLOAT value that indicates the sharpness of specular highlights. To turn off specular highlights for a material, set **Power** to 0 (setting **Specular** to 0 is not enough).

## See also

[SetMaterial](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmaterial)