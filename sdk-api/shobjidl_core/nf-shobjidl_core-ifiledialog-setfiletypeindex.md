# IFileDialog::SetFileTypeIndex

## Description

Sets the file type that appears as selected in the dialog.

## Parameters

### `iFileType` [in]

Type: **UINT**

The index of the file type in the file type array passed to [IFileDialog::SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes) in its *cFileTypes* parameter. Note that this is a one-based index, not zero-based.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method must be called before the dialog is showing.