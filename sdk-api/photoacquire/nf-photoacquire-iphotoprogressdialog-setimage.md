# IPhotoProgressDialog::SetImage

## Description

Sets either the thumbnail image displayed in the progress dialog box, the icon in the title bar of the progress dialog box, or the icon in ALT+TAB key combination windows.

## Parameters

### `nImageType` [in]

Integer value indicating the image type to set. Only one type of image type may be set at a time. The values passed to this parameter should not be considered a bit field and may not be combined with bitwise OR.

| Value | Meaning |
| --- | --- |
| **PROGRESS_DIALOG_ICON_SMALL** | The small icon used in the title bar (normally 16 x 16 pixels). |
| **PROGRESS_DIALOG_ICON_LARGE** | The icon used to represent the progress dialog box in Alt-Tab windows (normally 32 x 32 pixels). |
| **PROGRESS_DIALOG_ICON_THUMBNAIL** | An icon used in place of the thumbnail (up to 128 x 128 pixels). |
| **PROGRESS_DIALOG_BITMAP_THUMBNAIL** | A bitmap thumbnail (up to 128 x 128 pixels, although it will be scaled to fit if it is too large). |

### `hIcon` [in]

Handle to an icon object.

### `hBitmap` [in]

Handle to a bitmap object representing the thumbnail image.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)