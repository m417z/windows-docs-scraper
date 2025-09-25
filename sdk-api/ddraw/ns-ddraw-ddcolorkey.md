# DDCOLORKEY structure

## Description

The **DDCOLORKEY** structure describes a source color key, destination color key, or color space. A color key is specified if the low and high range values are the same. This structure is used with the [IDirectDrawSurface7::GetColorKey](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getcolorkey) and [IDirectDrawSurface7::SetColorKey](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-setcolorkey) methods.

## Members

### `dwColorSpaceLowValue`

Low value of the color range that is to be used as the color key.

### `dwColorSpaceHighValue`

High value of the color range that is to be used as the color key.