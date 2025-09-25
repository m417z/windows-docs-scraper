# Bitmap::InitializePalette

## Description

The **Bitmap::InitializePalette** method initializes a standard, optimal, or custom color palette.

## Parameters

### `palette` [in, out]

Type: **[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)***

Pointer to a buffer that contains a [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) structure followed by an array of **ARGB** values. You must set the **Flags** and **Count** members of the **ColorPalette** structure. The **Entries** member of a **ColorPalette** structure is an array of one **ARGB** value. You must allocate memory for the **ColorPalette** structure and for the additional **ARGB** values in the palette. For example, if the palette has 36 **ARGB** values, allocate a buffer as follows: `malloc(sizeof(ColorPalette) + 35*sizeof(ARGB))`.

### `palettetype` [in]

Type: **[PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype)**

Element of the [PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype) enumeration that specifies the palette type. The palette can have one of several standard types, or it can be a custom palette that you define. Also, the **Bitmap::InitializePalette** method can create an optimal palette based on a specified bitmap.

### `optimalColors` [in]

Type: **INT**

Integer that specifies the number of colors you want to have in an optimal palette based on a specified bitmap. If this parameter is greater than 0, the *palettetype* parameter must be set to **PaletteTypeOptimal**, and the *bitmap* parameter must point to a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object. If you are creating a standard or custom palette rather than an optimal palette, set this parameter to 0.

### `useTransparentColor` [in]

Type: **BOOL**

Boolean value that specifies whether to include the transparent color in the palette. Set to **TRUE** to include the transparent color; otherwise **FALSE**.

### `bitmap` [in]

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

Pointer to a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object for which an optimal palette will be created. If *palettetype* is set to **PaletteTypeOptimal** and *optimalColors* is set to a positive integer, set this parameter to the address of a **Bitmap** object. Otherwise, set this parameter to **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)