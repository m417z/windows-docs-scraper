# ColorLUTParams structure

## Description

A **ColorLUTParams** structure contains members (color lookup tables) that specify color adjustments to a bitmap.

You can apply a custom adjustment to a bitmap by following these steps.

1. Create a **ColorLUTParams** structure.
2. Each member of the **ColorLUTParams** structure is a color lookup table (array of 256 bytes) for a particular color channel, alpha, red, green, or blue. Assign values of your choice to the four lookup tables.
3. Pass the address of the **ColorLUTParams** structure to the [ColorLUT::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorlut-setparameters) method of a [ColorLUT](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorlut) object.
4. Pass the address of the [ColorLUT](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorlut) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `lutB`

Type: **ColorChannelLUT**

Array of 256 bytes that specifies the adjustment for the blue channel.

### `lutG`

Type: **ColorChannelLUT**

Array of 256 bytes that specifies the adjustment for the green channel.

### `lutR`

Type: **ColorChannelLUT**

Array of 256 bytes that specifies the adjustment for the red channel.

### `lutA`

Type: **ColorChannelLUT**

Array of 256 bytes that specifies the adjustment for the alpha channel.

## Remarks

A lookup table specifies how existing color channel values should be replaced by new values. A color channel value of j is replaced by the jth entry in the lookup table for that channel. For example, an existing blue channel value of 25 would be replaced by the value of lutB[25].

The ColorChannelLUT data type is defined in GdiplusColorMatrix.h as follows:

`typedef BYTE ColorChannelLUT[256];`