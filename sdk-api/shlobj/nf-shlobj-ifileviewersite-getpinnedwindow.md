# IFileViewerSite::GetPinnedWindow

## Description

Gets the handle to the current pinned window, if one exists.

## Parameters

### `phwnd` [out]

Type: **HWND***

A pointer to the handle of the current pinned window or **NULL** if no pinned window exists.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFileViewerSite](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ifileviewersite)