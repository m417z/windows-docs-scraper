# IFileDialogEvents::OnTypeChange

## Description

Called when the dialog is opened to notify the application of the initial chosen filetype.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called when the dialog is opened to notify the application of the initially chosen filetype. If the application has code in [IFileDialogEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogevents) that responds to type changes, it can respond to the type. For example, it could hide certain controls. The application controls the initial file type and could do its own checks, so this method is provided as a convenience.

## See also

[IFileDialog::GetFileTypeIndex](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb775958(v=vs.85))

[IFileDialogEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogevents)