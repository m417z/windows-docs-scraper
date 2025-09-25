# IPhotoProgressDialog::Destroy

## Description

The `Destroy` method closes and disposes of the progress dialog box shown during image enumeration and acquisition.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Calling `Destroy` is the only way to close the progress dialog box. If `Destroy` is not called, the dialog box will remain open. The dialog box is not automatically closed when the operation in progress completes.

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)