# IFileDialog2::SetCancelButtonLabel

## Description

Replaces the default text "Cancel" on the common file dialog's **Cancel** button.

## Parameters

### `pszLabel` [in]

Type: **LPCWSTR**

Pointer to a string that contains the new text to display on the button.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Changing the text on the Cancel button can be useful for situations where the IFileDialogEvents::OnFileOk method is used to accumulate items, and the button text should be Done instead of Cancel, for example.

## See also

[IFileDialog2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ifiledialog2)