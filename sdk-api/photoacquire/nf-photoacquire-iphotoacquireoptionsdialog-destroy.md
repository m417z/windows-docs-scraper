# IPhotoAcquireOptionsDialog::Destroy

## Description

The `Destroy` method closes and destroys the modeless dialog box created with the [Create](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireoptionsdialog-create) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If you destroy the parent window, the child window will automatically be destroyed.

## See also

[IPhotoAcquireOptionsDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireoptionsdialog)