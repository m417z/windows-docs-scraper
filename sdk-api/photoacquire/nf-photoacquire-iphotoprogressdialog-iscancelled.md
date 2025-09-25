# IPhotoProgressDialog::IsCancelled

## Description

The `IsCancelled` method indicates whether the operation has been canceled via the progress dialog box.

## Parameters

### `pfCancelled` [out]

Pointer to a flag that, if set to **TRUE**, indicates the action has been canceled.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed |

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)