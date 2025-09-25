# IPhotoProgressDialog::IsCheckboxChecked

## Description

The `IsCheckboxChecked` method indicates whether the check box in the progress dialog box (typically indicating whether to delete files after transfer) is selected.

## Parameters

### `nCheckboxId` [in]

Integer value containing the check box identifier (ID).

### `pfChecked` [out]

Pointer to a flag that, if set to **TRUE**, indicates that the check box is selected.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer was expected. |

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)