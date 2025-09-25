# IPhotoAcquireOptionsDialog::Create

## Description

The `Create` method creates and displays a modeless instance of the photo options dialog box, hosted within a parent window.

## Parameters

### `hWndParent` [in]

Handle to the parent window.

### `phWndDialog` [out]

Specifies the created dialog box.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The [Initialize](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireoptionsdialog-initialize) method should be called prior to the `Create` method.

The parent window indicated by *hWndParent* provides **OK** and **Cancel** buttons to the new dialog box instance.

## See also

[IPhotoAcquireOptionsDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireoptionsdialog)