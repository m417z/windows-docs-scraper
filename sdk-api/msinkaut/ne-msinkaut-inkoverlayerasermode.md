# InkOverlayEraserMode enumeration

## Description

Specifies the way in which ink is erased from the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object and the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control.

This mode is used when the [InkOverlayEditingMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayeditingmode) is set to Delete.

## Constants

### `IOERM_StrokeErase:0`

 Ink is erased by stroke.

This is the default value.

### `IOERM_PointErase:1`

Ink is erased by point.

## See also

[EraserMode Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_erasermode)

[EraserWidth Property [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_eraserwidth)

[InkOverlayEditingMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkoverlayeditingmode)