# IPhotoAcquireOptionsDialog::DoModal

## Description

The `DoModal` method creates and displays the options dialog box as a modal dialog box.

## Parameters

### `hWndParent` [in]

Handle to the dialog's parent window.

### `ppnReturnCode` [out]

Specifies the code returned when the window is closed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The modal dialog displayed by **DoModal** will have **OK** and **Cancel** buttons, whereas the **OK** and **Cancel** buttons of the modeless dialog displayed by [Create](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireoptionsdialog-create) must be provided by the parent window.

## See also

[IPhotoAcquireOptionsDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireoptionsdialog)