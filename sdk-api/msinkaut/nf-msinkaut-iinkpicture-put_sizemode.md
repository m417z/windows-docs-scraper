# IInkPicture::put_SizeMode

## Description

Gets or sets how the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control handles image placement and sizing.

This property is read/write.

## Parameters

## Remarks

Valid values for this property are taken from the [InkPictureSizeMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpicturesizemode) enumeration. By default, in **IPSM_Normal** mode, the picture is positioned in the upper-left corner of the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control, and any part of the image too big for the InkPicture control is clipped. Using the **IPSM_StretchImage** value causes the picture to stretch to fit the control.

Using the **IPSM_AutoSize** value causes the control to resize to always fit the picture. Using the **IPSM_CenterImage** value causes the picture to be centered in the control.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[InkPictureSizeMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkpicturesizemode)