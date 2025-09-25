# LevelsParams structure

## Description

The **LevelsParams** structure contains members that specify adjustments to the light, midtone, or dark areas of a bitmap.

You can adjust the light, midtone, or dark areas of a bitmap by following these steps.

1. Create and initialize a **LevelsParams** structure.
2. Pass the address of the **LevelsParams** structure to the [Levels::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-levels-setparameters) method of a [Levels](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-levels) object.
3. Pass the address of the [Levels](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-levels) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `highlight`

Type: **INT**

Integer in the range 0 through 100 that specifies which pixels should be lightened. You can use this adjustment to lighten pixels that are already lighter than a certain threshold. Setting **highlight** to 100 specifies no change. Setting **highlight** to t specifies that a color channel value is increased if it is already greater than t percent of full intensity. For example, setting **highlight** to 90 specifies that all color channel values greater than 90 percent of full intensity are increased.

### `midtone`

Type: **INT**

Integer in the range -100 through 100 that specifies how much to lighten or darken an image. Color channel values in the middle of the intensity range are altered more than color channel values near the minimum or maximum intensity. You can use this adjustment to lighten (or darken) an image without loosing the contrast between the darkest and lightest portions of the image. A value of 0 specifies no change. Positive values specify that the midtones are made lighter, and negative values specify that the midtones are made darker.

### `shadow`

Type: **INT**

Integer in the range 0 through 100 that specifies which pixels should be darkened. You can use this adjustment to darken pixels that are already darker than a certain threshold. Setting **shadow** to 0 specifies no change. Setting **shadow** to t specifies that a color channel value is decreased if it is already less than t percent of full intensity. For example, setting **shadow** to 10 specifies that all color channel values less than 10 percent of full intensity are decreased.