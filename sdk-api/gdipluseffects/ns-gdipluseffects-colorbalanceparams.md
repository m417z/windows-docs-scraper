# ColorBalanceParams structure

## Description

A **ColorBalanceParams** structure contains members that specify the nature of a color balance adjustment.

You can change the color balance of a bitmap by following these steps.

1. Create and initialize a **ColorBalanceParams** structure.
2. Pass the address of the **ColorBalanceParams** structure to the [ColorBalance::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorbalance-setparameters) method of a [ColorBalance](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorbalance) object.
3. Pass the address of the [ColorBalance](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorbalance) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `cyanRed`

Type: **INT**

Integer in the range -100 through 100 that specifies a change in the amount of red in the image. If the value is 0, there is no change. As the value moves from 0 to 100, the amount of red in the image increases and the amount of cyan decreases. As the value moves from 0 to -100, the amount of red in the image decreases and the amount of cyan increases.

### `magentaGreen`

Type: **INT**

Integer in the range -100 through 100 that specifies a change in the amount of green in the image. If the value is 0, there is no change. As the value moves from 0 to 100, the amount of green in the image increases and the amount of magenta decreases. As the value moves from 0 to -100, the amount of green in the image decreases and the amount of magenta increases.

### `yellowBlue`

Type: **INT**

Integer in the range -100 through 100 that specifies a change in the amount of blue in the image. If the value is 0, there is no change. As the value moves from 0 to 100, the amount of blue in the image increases and the amount of yellow decreases. As the value moves from 0 to -100, the amount of blue in the image decreases and the amount of yellow increases.