# LinearGradientBrush::SetGammaCorrection

## Description

The **LinearGradientBrush::SetGammaCorrection** method specifies whether gamma correction is enabled for this linear gradient brush.

## Parameters

### `useGammaCorrection` [in]

Type: **BOOL**

Boolean value that specifies whether gamma correction occurs during rendering. **TRUE** specifies that gamma correction is enabled, and **FALSE** specifies that gamma correction is not enabled. By default, gamma correction is disabled during construction of a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Gamma correction is often done to match the intensity contrast of the gradient to the ability of the human eye to perceive intensity changes.

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetGammaCorrection](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-getgammacorrection)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)