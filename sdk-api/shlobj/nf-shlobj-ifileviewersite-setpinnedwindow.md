# IFileViewerSite::SetPinnedWindow

## Description

Sets the pinned window. When the user selects a new file to view, the Shell directs the file viewer to display the new file in the pinned window instead of creating a new window.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the new pinned window or **NULL** if there is to be no pinned window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFileViewerSite](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ifileviewersite)