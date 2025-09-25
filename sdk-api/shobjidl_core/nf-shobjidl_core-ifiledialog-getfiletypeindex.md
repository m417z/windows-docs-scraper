# IFileDialog::GetFileTypeIndex

## Description

Gets the currently selected file type.

## Parameters

### `piFileType` [out]

Type: **UINT***

A pointer to a **UINT** value that receives the index of the selected file type in the file type array passed to [IFileDialog::SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes) in its *cFileTypes* parameter.

**Note** This is a one-based index rather than zero-based.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IFileDialog::GetFileTypeIndex** can be called either while the dialog is open or after it has closed.