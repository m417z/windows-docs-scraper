# IPhotoProgressDialog::SetCheckboxText

## Description

The `SetCheckboxText` method sets the text for the check box in the progress dialog box indicating whether to delete images after transfer.

## Parameters

### `nCheckboxId` [in]

Integer containing the check box identifier (ID).

### `pszCheckboxText` [in]

Pointer to a null-terminated string containing the check box text.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)