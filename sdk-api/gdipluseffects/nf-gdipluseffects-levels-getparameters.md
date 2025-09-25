# Levels::GetParameters

## Description

The **Levels::GetParameters** method gets the current values of the parameters of this [Levels](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-levels) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [LevelsParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-levelsparams) structure.

### `parameters` [out]

Type: **[LevelsParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-levelsparams)***

Pointer to a [LevelsParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-levelsparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Levels](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-levels)

[Levels::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-levels-setparameters)