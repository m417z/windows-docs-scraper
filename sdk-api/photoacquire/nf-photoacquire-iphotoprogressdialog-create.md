# IPhotoProgressDialog::Create

## Description

The `Create` method creates and displays a progress dialog box that can be shown during image enumeration and acquisition.

## Parameters

### `hwndParent` [in]

Handle of the parent window.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The dialog box that is created is modal, and runs in its own thread.

To close the dialog, call [Destroy](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoprogressdialog-destroy).

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)

[IPhotoProgressDialog::Destroy](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoprogressdialog-destroy)