# PROGRESS_DIALOG_IMAGE_TYPE enumeration

## Description

The `PROGRESS_DIALOG_IMAGE_TYPE` enumeration type indicates the image type set in [IPhotoProgressDialog::SetImage](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoprogressdialog-setimage).

## Constants

### `PROGRESS_DIALOG_ICON_SMALL:0`

Specifies the small icon used in the title bar (normally 16 x 16 pixels).

### `PROGRESS_DIALOG_ICON_LARGE:0x1`

Specifies the icon used to represent the progress dialog box in ALT+TAB key combination windows (normally 32 x 32 pixels).

### `PROGRESS_DIALOG_ICON_THUMBNAIL:0x2`

Specifies an icon used in place of the thumbnail (up to 128 x 128 pixels).

### `PROGRESS_DIALOG_BITMAP_THUMBNAIL:0x3`

Specifies a bitmap thumbnail (up to 128 x 128 pixels, although it will be scaled to fit if it is too large).

## See also

[Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/acquisition/enumeration-types)

[IPhotoAcquireProgressDialog::SetImage](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoprogressdialog-setimage)