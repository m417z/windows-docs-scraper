# IFileDialog::SetDefaultExtension

## Description

Sets the default extension to be added to file names.

## Parameters

### `pszDefaultExtension` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the extension text. This string should not include a leading period. For example, "jpg" is correct, while ".jpg" is not.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method is called before showing the dialog, the dialog will update the default extension automatically when the user chooses a new file type (see [SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes)).