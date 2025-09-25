# ColorLUT::GetParameters

## Description

The **ColorLUT::GetParameters** method gets the current values of the parameters of this [ColorLUT](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorlut) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [ColorLUTParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorlutparams) structure.

### `lut` [out]

Type: **[ColorLUTParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorlutparams)***

Pointer to a [ColorLUTParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorlutparams) structure that receives the parameter values.

## Return value

This method does not return a value.

## See also

[ColorLUT](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorlut)

[ColorLUT::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorlut-setparameters)