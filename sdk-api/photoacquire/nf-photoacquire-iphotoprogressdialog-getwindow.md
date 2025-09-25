# IPhotoProgressDialog::GetWindow

## Description

The `GetWindow` method retrieves the handle to the progress dialog box.

## Parameters

### `phwndProgressDialog` [out]

Specifies the handle to the progress dialog box.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Pointer passed was **NULL** |

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)