# InkPictureSizeMode enumeration

## Description

Specifies how the picture behaves inside the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control.

The mode is set by using the [SizeMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_sizemode) property and is applied to the picture set with the [Picture](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_picture) property.

## Constants

### `IPSM_AutoSize:0`

The control auto sizes to fit the picture.

### `IPSM_CenterImage:1`

The picture is centered within the control.

### `IPSM_Normal:2`

The picture appears at its regular size within the control.

### `IPSM_StretchImage:3`

 The picture is stretched within the control.

## See also

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)