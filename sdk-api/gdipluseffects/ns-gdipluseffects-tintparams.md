# TintParams structure

## Description

A **TintParams** structure contains members that specify the nature of a tint adjustment to a bitmap.

You can adjust the tint of a bitmap by following these steps.

1. Create and initialize a **TintParams** structure.
2. Pass the address of the **TintParams** structure to the [Tint::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-tint-setparameters) method of a [Tint](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-tint) object.
3. Pass the address of the [Tint](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-tint) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `hue`

Type: **INT**

Integer in the range -180 through 180 that specifies the hue to be strengthened or weakened. A value of 0 specifies blue. A positive value specifies a clockwise angle on the color wheel. For example, positive 60 specifies cyan and positive 120 specifies green. A negative value specifies a counter-clockwise angle on the color wheel. For example, negative 60 specifies magenta and negative 120 specifies red.

### `amount`

Type: **INT**

Integer in the range -100 through 100 that specifies how much the hue (given by the **hue** parameter) is strengthened or weakened. A value of 0 specifies no change. Positive values specify that the hue is strengthened and negative values specify that the hue is weakened.