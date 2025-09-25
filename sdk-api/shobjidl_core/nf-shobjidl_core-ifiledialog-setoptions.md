# IFileDialog::SetOptions

## Description

Sets flags to control the behavior of the dialog.

## Parameters

### `fos` [in]

Type: **FILEOPENDIALOGOPTIONS**

One or more of the [FILEOPENDIALOGOPTIONS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_fileopendialogoptions) values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Generally, this method should take the value that was retrieved by [IFileDialog::GetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getoptions) and modify it to include or exclude options by setting the appropriate flags.